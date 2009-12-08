--- os_freebsd.cpp.orig	2008-03-04 23:09:47.000000000 +0100
+++ os_freebsd.cpp	2008-03-14 13:52:37.000000000 +0100
@@ -525,7 +524,7 @@
     return -1;
   }

-  if ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
+  if (((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) && ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_SCSI_STATUS_ERROR)) {
  #if __FreeBSD_version > 500000
     cam_error_print(cam_dev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
  #endif
