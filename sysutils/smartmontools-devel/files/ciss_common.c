/*
 * This bits are ripped almost verbatim from os_linux.cpp to allow
 * FreeBSD, which has the same ciss-ioctls as Linux, to access
 * individual drives behind ciss(4) controllers.
 * Authors of smartmontools may wish to make this code shared between
 * *BSD and Linux, but * currently it remains a duplicate.
 *
 *	Mikhail T. <mi@aldan.algebra.com>
 */

/*
 * This header is not currently installed under /usr/include. Thus
 * having a kernel source tree is required to compile this file. Use:
 *
 *	-I/sys/dev/ciss
 *
 * to build. Rather unfortunate...
 */
#include <cissio.h>

#define SEND_IOCTL_RESP_SENSE_LEN 16    /* ioctl limitation */
#define LSCSI_DRIVER_SENSE  0x8 /* alternate CHECK CONDITION indication */

static int cciss_io_interface(int device, int target,
			      struct scsi_cmnd_io * iop, int report);

typedef int8_t	BYTE; /* some kind of Linuxism? */
typedef uint32_t DWORD;

typedef struct _ReportLUNdata_struct
{
  BYTE LUNListLength[4];
  DWORD reserved;
  BYTE LUN[CISS_MAX_LUN][8];
} ReportLunData_struct;

/* Structure/defines of Report Physical LUNS of drive */
#define CISS_MAX_LUN        16
#define CISS_MAX_PHYS_LUN   1024
#define CISS_REPORT_PHYS    0xc3

// CCISS Smart Array Controller
static int cciss_sendpassthru(unsigned int cmdtype, unsigned char *CDB,
    			unsigned int CDBlen, char *buff,
    			unsigned int size, unsigned int LunID,
    			unsigned char *scsi3addr, int fd)
{
    int err ;
    IOCTL_Command_struct iocommand;

    memset(&iocommand, 0, sizeof(iocommand));

    if (cmdtype == 0) 
    {
        // To controller; nothing to do
    }
    else if (cmdtype == 1) 
    {
        iocommand.LUN_info.LogDev.VolId = LunID;
        iocommand.LUN_info.LogDev.Mode = 1;
    }
    else if (cmdtype == 2) 
    {
        memcpy(&iocommand.LUN_info.LunAddrBytes,scsi3addr,8);
        iocommand.LUN_info.LogDev.Mode = 0;
    }
    else 
    {
        fprintf(stderr, "cciss_sendpassthru: bad cmdtype\n");
        return 1;
    }

    memcpy(&iocommand.Request.CDB[0], CDB, CDBlen);
    iocommand.Request.CDBLen = CDBlen;
    iocommand.Request.Type.Type = TYPE_CMD;
    iocommand.Request.Type.Attribute = ATTR_SIMPLE;
    iocommand.Request.Type.Direction = XFER_READ;
    iocommand.Request.Timeout = 0;

    iocommand.buf_size = size;
    iocommand.buf = (unsigned char *)buff;

    if ((err = ioctl(fd, CCISS_PASSTHRU, &iocommand))) 
    {
        perror("CCISS ioctl error");
    }
    return err;
}

static int cciss_getlun(int device, int target, unsigned char *physlun)
{
    unsigned char CDB[16]= {0};
    ReportLunData_struct *luns;
    int reportlunsize = sizeof(*luns) + CISS_MAX_PHYS_LUN * 8;
    int i;
    int ret;

    luns = (ReportLunData_struct *)malloc(reportlunsize);

    memset(luns, 0, reportlunsize);

    /* Get Physical LUN Info (for physical device) */
    CDB[0] = CISS_REPORT_PHYS;
    CDB[6] = (reportlunsize >> 24) & 0xFF;  /* MSB */
    CDB[7] = (reportlunsize >> 16) & 0xFF;
    CDB[8] = (reportlunsize >> 8) & 0xFF;
    CDB[9] = reportlunsize & 0xFF;

    if ((ret = cciss_sendpassthru(0, CDB, 12, (char *)luns, reportlunsize, 0, NULL, device)))
    {
        free(luns);
        return ret;
    }

    for (i=0; i<CISS_MAX_LUN+1; i++) 
    {
        if (luns->LUN[i][6] == target) 
        {
            memcpy(physlun, luns->LUN[i], 8);
            free(luns);
            return 0;
        }
    }

    free(luns);
    return ret;
}
// end CCISS Smart Array Controller

/* cciss >> CCSISS I/O passthrough
   This is an interface that uses the cciss passthrough to talk to the SMART controller on
   the HP system. The cciss driver provides a way to send SCSI cmds through the CCISS passthrough
   essentially the methods above and below pertain to SCSI, except for the SG driver which is not
   involved. The CCISS driver does not engage the scsi subsystem. */
 static int cciss_io_interface(int device, int target, struct scsi_cmnd_io * iop, int report)
 {
     unsigned char pBuf[512] = {0};
     unsigned char phylun[1024] = {0};
     int iBufLen = 512;
     int status = -1;
     int len = 0; // used later in the code.
     report = 0;
 
     cciss_getlun(device, target, phylun);
     status = cciss_sendpassthru( 2, iop->cmnd, iop->cmnd_len, (char*) pBuf, iBufLen, 1, phylun, device);
 
     if (0 == status)
     {
         if (report > 0)
             printf("  status=0\n");
         if (DXFER_FROM_DEVICE == iop->dxfer_dir)
         {
             memcpy(iop->dxferp, pBuf, iop->dxfer_len);
             if (report > 1)
             {
                 int trunc = (iop->dxfer_len > 256) ? 1 : 0;
                 printf("  Incoming data, len=%d%s:\n", (int)iop->dxfer_len,
                      (trunc ? " [only first 256 bytes shown]" : ""));
                 dStrHex((const char*)iop->dxferp, (trunc ? 256 : iop->dxfer_len) , 1);
             }
         }
         return 0;
     }
     iop->scsi_status = status & 0x7e; /* bits 0 and 7 used to be for vendors */
     if (LSCSI_DRIVER_SENSE == ((status >> 24) & 0xf))
         iop->scsi_status = SCSI_STATUS_CHECK_CONDITION;
     len = (SEND_IOCTL_RESP_SENSE_LEN < iop->max_sense_len) ?
                SEND_IOCTL_RESP_SENSE_LEN : iop->max_sense_len;
     if ((SCSI_STATUS_CHECK_CONDITION == iop->scsi_status) &&
         iop->sensep && (len > 0))
     {
         memcpy(iop->sensep, pBuf, len);
         iop->resp_sense_len = iBufLen;
         if (report > 1)
         {
             printf("  >>> Sense buffer, len=%d:\n", (int)len);
             dStrHex((const char *)pBuf, len , 1);
         }
     }
     if (report)
     {
         if (SCSI_STATUS_CHECK_CONDITION == iop->scsi_status) {
             printf("  status=%x: sense_key=%x asc=%x ascq=%x\n", status & 0xff,
                  pBuf[2] & 0xf, pBuf[12], pBuf[13]);
         }
         else
             printf("  status=0x%x\n", status);
     }
     if (iop->scsi_status > 0)
         return 0;
     else
     {
         if (report > 0)
             printf("  ioctl status=0x%x but scsi status=0, fail with EIO\n", status);
         return -EIO;      /* give up, assume no device there */
     }
 } 
