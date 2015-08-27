--- libvo/vo_v4l2.c.orig	2015-08-26 13:36:16 UTC
+++ libvo/vo_v4l2.c
@@ -33,9 +33,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <inttypes.h>
-#include <linux/types.h>
 #include <linux/videodev2.h>
-#include <linux/ioctl.h>
 
 #include "mp_msg.h"
 #include "subopt-helper.h"
