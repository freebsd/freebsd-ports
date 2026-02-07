#include <sys/types.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cam/scsi/scsi_message.h>
#include <camlib.h>

#include "mmc_device.h"

#include "util/logging.h"
#include "util/macro.h"
#include "util/strutl.h"

#define CDB_LEN 12

struct mmcdev {
    struct cam_device *cam_dev;
};

int device_send_cmd(MMCDEV *dev, const uint8_t *cmd, uint8_t *buf, size_t tx, size_t rx)
{
    char str[512];
    int result = 0;
    union ccb *ccb;

    if (buf == NULL) {
        return 0;
    }

    ccb = cam_getccb(dev->cam_dev);
    if (ccb == NULL) {
        BD_DEBUG(DBG_MMC, "cam_getccb failed\n");
        return 0;
    }

    memcpy(ccb->csio.cdb_io.cdb_bytes, cmd, CDB_LEN);

    cam_fill_csio(&ccb->csio,
            /*retries*/ 0,
            /*cbfcnp*/ NULL,
            /*flags*/ CAM_DEV_QFRZDIS | (tx?CAM_DIR_OUT:CAM_DIR_IN),
            /*tag_action*/ MSG_SIMPLE_Q_TAG,
            /*data_ptr*/ buf,
            /*dxfer_len*/ (tx?tx:rx),
            /*sense_len*/ SSD_FULL_SIZE,
            /*cdb_len*/ CDB_LEN,
            /*timeout*/ 5000);

    BD_DEBUG(DBG_MMC, "Send BSD MMC cmd %s:\n", str_print_hex(str, cmd, 16));
    if (tx) {
        BD_DEBUG(DBG_MMC, "  Buffer: %s ->\n", str_print_hex(str, buf, tx>255?255:tx));
    }

    if (cam_send_ccb(dev->cam_dev, ccb) < 0) {
        BD_DEBUG(DBG_MMC, "cam_send_ccb failed: %s\n", strerror(errno));
        cam_error_print(dev->cam_dev, ccb, CAM_ESF_ALL, CAM_EPF_ALL, stderr);
    } else if ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
        BD_DEBUG(DBG_MMC, "cam_send_ccb failed with status: %02X\n", ccb->ccb_h.status);
        cam_error_print(dev->cam_dev, ccb, CAM_ESF_ALL, CAM_EPF_ALL, stderr);
    } else {
        result = 1;
    }

    cam_freeccb(ccb);

    if (result > 0) {
        if (!tx) {
            BD_DEBUG(DBG_MMC, "  Buffer: %s <-\n", str_print_hex(str, buf, rx>255?255:rx));
        }
        BD_DEBUG(DBG_MMC, "  Send succeeded!\n");
    } else {
        BD_DEBUG(DBG_MMC, "  Send failed!\n");
    }

    return result;
}

MMCDEV *device_open(const char *path)
{
    struct cam_device *cam_dev;
    cam_dev = cam_open_device(path, O_RDWR);
    if (cam_dev == NULL) {
        BD_DEBUG(DBG_MMC | DBG_CRIT, "cam_open_device failed: %s\n", cam_errbuf);
        return NULL;
    }

    MMCDEV *dev = calloc(1, sizeof(MMCDEV));
    if (!dev) {
        cam_close_device(cam_dev);
        return NULL;
    }

    dev->cam_dev = cam_dev;

    return dev;
}

void device_close(MMCDEV **pp)
{
    if (pp && *pp) {
        if ((*pp)->cam_dev != NULL) {
            cam_close_device((*pp)->cam_dev);
        }

        X_FREE(*pp);
    }
}
