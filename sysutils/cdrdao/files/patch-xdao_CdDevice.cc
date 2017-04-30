--- xdao/CdDevice.cc.orig	2009-02-21 13:49:17 UTC
+++ xdao/CdDevice.cc
@@ -255,7 +255,7 @@ int CdDevice::updateStatus()
 
 bool CdDevice::updateProgress(Glib::IOCondition cond, int fd)
 {
-  static char msgSync[4] = { 0xff, 0x00, 0xff, 0x00 };
+  static unsigned char msgSync[4] = { 0xff, 0x00, 0xff, 0x00 };
   fd_set fds;
   int state = 0;
   char buf[10];
