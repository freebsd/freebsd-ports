--- ./libfprint/drivers/vfs301_proto.c.ORIG	2013-06-26 14:13:00.000000000 +0200
+++ ./libfprint/drivers/vfs301_proto.c	2014-04-21 11:09:19.000000000 +0200
@@ -33,7 +33,7 @@
 #include <stdio.h>
 #include <assert.h>
 #include <stdlib.h>
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 
 #include "vfs301_proto.h"
 #include "vfs301_proto_fragments.h"
