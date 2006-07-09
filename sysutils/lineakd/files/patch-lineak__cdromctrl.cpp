--- lineak/cdromctrl.cpp.orig	Fri May 26 14:34:03 2006
+++ lineak/cdromctrl.cpp	Fri May 26 14:39:48 2006
@@ -21,7 +21,7 @@
 extern "C" {
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#if defined (__FreeBSD_kernel__) || defined(__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined(__FreeBSD__)
 # include <sys/cdio.h>
 # define CDROMEJECT CDIOCEJECT /*_IO('c', 107)*/
 # define CDROMCLOSETRAY CDIOCCLOSE
@@ -37,6 +37,7 @@
 #  include <scsi/scsi.h>
 #  include <scsi/sg.h>
 #  include <scsi/scsi_ioctl.h>
+#  include <sys/mount.h>
 #endif
 #if defined (__CYGWIN__)
 #  include <windows.h>
@@ -47,7 +48,6 @@
 
 #include <sys/stat.h>
 #include <sys/types.h>
-#include <sys/mount.h>
 
 #include <stdio.h>
 #include <errno.h>
