--- libavutil/common.h.orig	2010-04-26 23:01:38.000000000 +0200
+++ libavutil/common.h	2010-07-10 16:06:27.038027901 +0200
@@ -36,6 +36,10 @@
 #include <string.h>
 #include "attributes.h"
 
+#ifndef	UINT64_C
+#define	UINT64_C(c)		(c ## UL)
+#endif
+
 //rounded division & shift
 #define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
 /* assume b>0 */
