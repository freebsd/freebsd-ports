--- getMB-smb.c.orig	2004-08-17 01:32:39 UTC
+++ getMB-smb.c
@@ -31,6 +31,7 @@
 #endif
 
 #ifdef HAVE_SMBUS
+#include <osreldate.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
@@ -90,7 +91,9 @@ OpenIO(void) {
   }
 
   cmd.cmd = 0x47;
+#if (__FreeBSD_version < 1100071)
   cmd.data.byte_ptr = &byte;
+#endif
   for (i = 0; i < sizeof(addrs); i++) {
     cmd.slave = addrs[i];
     if (ioctl(iosmb, SMB_READB, (caddr_t)&cmd) != -1) {
@@ -115,7 +118,11 @@ WriteByte(int addr,int value) {
   count = 0;
   cmd.slave = smb_addr;
   cmd.cmd = addr;
+#if (__FreeBSD_version >= 1100071)
+  cmd.wdata.byte = value;
+#else
   cmd.data.byte = value;
+#endif
   while (ioctl(iosmb, SMB_WRITEB, &cmd) == -1) {
     if (++count < 3) {
       sleep(1);
@@ -136,7 +143,12 @@ ReadByte(int addr) {
 
   cmd.slave = smb_addr;
   cmd.cmd = addr;
+#if (__FreeBSD_version >= 1100071)
+  cmd.rbuf = &ret; 
+  cmd.rcount = 1;
+#else
   cmd.data.byte_ptr = &ret;
+#endif
   while (ioctl(iosmb, SMB_READB, &cmd) == -1) {
     if (++count < 3) {
       sleep(1);
