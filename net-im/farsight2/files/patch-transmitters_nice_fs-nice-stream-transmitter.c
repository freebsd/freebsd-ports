--- transmitters/nice/fs-nice-stream-transmitter.c.orig	2010-03-20 18:53:45.000000000 -0400
+++ transmitters/nice/fs-nice-stream-transmitter.c	2010-03-20 18:55:10.000000000 -0400
@@ -46,8 +46,6 @@
 #include <string.h>
 #include <sys/types.h>
 
-#include <udp-bsd.h>
-
 #define GST_CAT_DEFAULT fs_nice_transmitter_debug
 
 /* Signals */
