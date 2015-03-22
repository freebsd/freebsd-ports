--- libavutil/common.h.orig	2010-07-07 19:27:45.000000000 +0200
+++ libavutil/common.h	2010-08-01 22:27:42.964629491 +0200
@@ -36,6 +36,10 @@
 #include <string.h>
 #include "attributes.h"
 
+#ifndef	UINT64_C
+#define	UINT64_C(c)	(c ## UL)
+#endif
+
 //rounded division & shift
 #define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
 /* assume b>0 */
