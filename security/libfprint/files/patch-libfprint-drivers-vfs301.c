--- libfprint/drivers/vfs301.c.orig	2017-01-05 17:18:55 UTC
+++ libfprint/drivers/vfs301.c
@@ -27,7 +27,7 @@
 #include <stdio.h>
 #include <assert.h>
 #include <stdlib.h>
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 
 #include "vfs301_proto.h"
 #include <unistd.h>
