--- os_freebsd.c.orig	Sat Nov  1 02:34:37 2003
+++ os_freebsd.c	Sat Nov  1 02:40:19 2003
@@ -402,13 +402,17 @@
 
   if (cam_send_ccb(cam_dev,ccb) < 0) {
     warn("error sending SCSI ccb");
+ #if __FreeBSD_version > 500000
     cam_error_print(cam_dev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
+ #endif
     cam_freeccb(ccb);
     return -1;
   }
 
   if ((ccb->ccb_h.status & CAM_STATUS_MASK) != CAM_REQ_CMP) {
+ #if __FreeBSD_version > 500000
     cam_error_print(cam_dev,ccb,CAM_ESF_ALL,CAM_EPF_ALL,stderr);
+ #endif
     cam_freeccb(ccb);
     return -1;
   }
@@ -426,8 +430,10 @@
     cam_close_device(cam_dev);
 
   if (report > 0) {
+    int trunc;
+
     pout("  status=0\n");
-    int trunc = (iop->dxfer_len > 256) ? 1 : 0;
+    trunc = (iop->dxfer_len > 256) ? 1 : 0;
     
     pout("  Incoming data, len=%d%s:\n", (int)iop->dxfer_len,
 	 (trunc ? " [only first 256 bytes shown]" : ""));
@@ -444,6 +450,9 @@
 
 
 static int get_ata_channel_unit ( const char* name, int* unit, int* dev) {
+#ifndef ATAREQUEST
+	return -1;
+#else
   // there is no direct correlation between name 'ad0, ad1, ...' and
   // channel/unit number.  So we need to iterate through the possible
   // channels and check each unit to see if we match names
@@ -483,6 +492,7 @@
     return -1;
   else
     return 0;
+#endif
 }
 
 
