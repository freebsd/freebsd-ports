--- ftdi-eeprom.c.orig	2003-02-16 07:02:56.000000000 +0300
+++ ftdi-eeprom.c	2009-08-17 00:38:28.000000000 +0400
@@ -34,6 +34,7 @@
  */
 
 #include <sys/ioctl.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -44,6 +45,9 @@
 #include <string.h>
 #include <limits.h>
 #include <dev/usb/usb.h>
+#if __FreeBSD_version >= 800069
+#include <dev/usb/usb_ioctl.h>
+#endif
 
 #include "ftdi-eeprom.h"
 
