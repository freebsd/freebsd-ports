--- ftdi-eeprom.c.orig	2009-08-09 11:21:23.000000000 +0400
+++ ftdi-eeprom.c	2009-08-09 11:21:37.000000000 +0400
@@ -44,6 +44,7 @@
 #include <string.h>
 #include <limits.h>
 #include <dev/usb/usb.h>
+#include <dev/usb/usb_ioctl.h>
 
 #include "ftdi-eeprom.h"
 
