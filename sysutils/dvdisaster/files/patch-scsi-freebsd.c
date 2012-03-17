--- scsi-freebsd.c.orig	2012-03-14 18:59:03.409149568 +0000
+++ scsi-freebsd.c	2012-03-14 19:28:12.104788317 +0000
@@ -194,7 +194,7 @@
 
    /* Extract sense data */
 
-   memcpy(sense, &(ccb->csio.sense_data), sizeof(struct scsi_sense_data));
+   memcpy(sense, &(ccb->csio.sense_data), sizeof(Sense));
 
    if((ccb->ccb_h.status & CAM_STATUS_MASK) == CAM_REQ_CMP)
      return 0;
