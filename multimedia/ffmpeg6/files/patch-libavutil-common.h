--- libavutil/common.h.orig	2025-11-23 02:58:01 UTC
+++ libavutil/common.h
@@ -43,6 +43,10 @@
 #include "error.h"
 #include "macros.h"
 
+#ifndef	UINT64_C
+#define	UINT64_C(c)	(c ## UL)
+#endif
+
 //rounded division & shift
 #define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
 /* assume b>0 */
