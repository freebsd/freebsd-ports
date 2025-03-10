--- libavutil/common.h.orig	2024-05-15 16:55:52 UTC
+++ libavutil/common.h
@@ -50,6 +50,10 @@
 #   define AV_NE(be, le) (le)
 #endif
 
+#ifndef		UINT64_C
+#define		UINT64_C(c)	(c ## UL)
+#endif
+
 //rounded division & shift
 #define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
 /* assume b>0 */
