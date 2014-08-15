--- ./libfprint/drivers/vfs301.c.ORIG	2013-06-26 14:13:00.000000000 +0200
+++ ./libfprint/drivers/vfs301.c	2014-04-21 11:09:12.000000000 +0200
@@ -27,7 +27,7 @@
 #include <stdio.h>
 #include <assert.h>
 #include <stdlib.h>
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 
 #include "vfs301_proto.h"
 #include <unistd.h>
