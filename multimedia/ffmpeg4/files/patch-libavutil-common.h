--- libavutil/common.h.orig	2015-06-19 20:44:53 UTC
+++ libavutil/common.h
@@ -49,6 +49,10 @@
 #   define AV_NE(be, le) (le)
 #endif
 
+#ifndef	UINT64_C
+#define	UINT64_C(c)	(c ## UL)
+#endif
+
 //rounded division & shift
 #define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
 /* assume b>0 */
