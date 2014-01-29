--- os_freebsd.cpp.orig	2013-07-05 12:40:38.000000000 +0200
+++ os_freebsd.cpp	2013-12-25 20:54:46.000000000 +0100
@@ -445,7 +445,8 @@
   }
 
   if ((ccb.ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
-    cam_error_print(m_camdev, &ccb, CAM_ESF_ALL, CAM_EPF_ALL, stderr);
+    if(scsi_debugmode > 0)
+      cam_error_print(m_camdev, &ccb, CAM_ESF_ALL, CAM_EPF_ALL, stderr);
     set_err(EIO);
     return -1;
   }
@@ -997,13 +998,15 @@
 
   if (cam_send_ccb(m_camdev,ccb) < 0) {
     warn("error sending SCSI ccb");
-    cam_error_print(m_camdev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
+    if (report > 0)
+      cam_error_print(m_camdev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
     cam_freeccb(ccb);
     return -EIO;
   }
 
-  if (((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) && ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_SCSI_STATUS_ERROR)) {
-    cam_error_print(m_camdev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
+  if ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
+    if(report > 0)
+      cam_error_print(m_camdev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
     cam_freeccb(ccb);
     return -EIO;
   }
