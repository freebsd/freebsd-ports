--- src/input/input_vcd.c.orig	Thu Sep 28 06:51:16 2006
+++ src/input/input_vcd.c	Thu Sep 28 07:03:55 2006
@@ -25,7 +25,6 @@
 #include "config.h"
 #endif
 
-#include <netinet/in.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/stat.h>
@@ -34,6 +33,7 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <string.h>
+#include <netinet/in.h>
 #ifdef HAVE_LINUX_CDROM_H
 # include <linux/cdrom.h>
 #endif
