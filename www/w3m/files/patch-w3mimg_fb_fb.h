--- w3mimg/fb/fb.h.orig	2003-07-08 00:48:17.000000000 +0900
+++ w3mimg/fb/fb.h	2007-11-23 02:43:22.000000000 +0900
@@ -1,7 +1,11 @@
 /* $Id: fb.h,v 1.7 2003/07/07 15:48:17 ukai Exp $ */
 #ifndef fb_header
 #define fb_header
+#if defined(__linux__)
 #include <linux/fb.h>
+#elif defined(__FreeBSD__)
+#include <sys/fbio.h> 
+#endif
 
 typedef struct {
     int num;
