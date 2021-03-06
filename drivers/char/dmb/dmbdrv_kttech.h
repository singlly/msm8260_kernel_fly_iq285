#ifndef __DMBDRVH__
#define __DMBDRVH__


#define DMB_IOCTL_INIT 0x0700
#define DMB_IOCTL_CLOSE 0x0701
#define DMB_IOCTL_SCAN_ENSEMBLE 0x0702
#define DMB_IOCTL_SERVICE_START 0x0703
#define DMB_IOCTL_SERVICE_END 0x0704
#define DMB_IOCTL_GET_PREBER  0x0705
#define DMB_IOCTL_GET_POSTBER  0x0706
#define DMB_IOCTL_GET_CER       0x0707
#define DMB_IOCTL_GET_RSSI      0x0708
#define DMB_IOCTL_SET_I2C_RETRY 0x0709
#define DMB_IOCTL_SET_I2C_TIMEOUT 0x070a
#define DMB_IOCTL_GET_CHIPID 0x070b
#define DMB_IOCTL_SET_ABORT  0x070c

#define MAX_ENSEMBLE_CHANNEL 30
#define MAX_DMB_CHANNEL 100

#define MAX_LABEL_LEN 16
#define MAX_CH_NUM 100


typedef struct
{
  unsigned int  freq;
  unsigned char subch_id;
  unsigned char type;
  unsigned char tm_id;
  char  channel_label[MAX_LABEL_LEN];
  char  ensemble_label[MAX_LABEL_LEN];
  unsigned short  ensemble_id;
  unsigned short  bit_rate;
#if 0  
  unsigned short  uiStarAddr;
  unsigned char ucSlFlag;
  unsigned char ucTableIndex;
  unsigned char ucOption;
  unsigned char ucProtectionLevel;
  unsigned short  uiDifferentRate;
  unsigned short  uiSchSize;

  unsigned int  ulServiceID;
  unsigned short  uiPacketAddr;
#endif
} DMB_CH_DATA_S;

typedef struct
{
	unsigned int freq;
	DMB_CH_DATA_S channel_data[MAX_ENSEMBLE_CHANNEL];
	int channel_count;
} ensemble_scan_req_t;

typedef struct
{
	unsigned int freq; // ensemble frequency
	int subch_id; // subchannel service ID
	int serv_type; // subchannel service type
	int tmid; // tmID, DMB->1, DAB->0
	int result; //0==success, -1==signal start fail, -2==abort
} service_start_req_t;

#define DMBLOG 

struct tdmb_platform_data {
	int (*power)(int);
	int (*setup)(void);
	void (*teardown)(void);
    int reset;
    int demod_enable;
};

int dmbi2c_reg_read(unsigned short reg_addr, unsigned char* buf, int len);
int dmbi2c_reg_readw(unsigned short reg_addr, unsigned short *pvalue);
int dmbi2c_reg_writew(unsigned short reg_addr, unsigned short pvalue);
#endif
