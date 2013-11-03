--- ./H/TermExt.h.orig	2012-06-30 16:53:59.000000000 -0300
+++ ./H/TermExt.h	2013-11-03 01:59:03.000000000 -0200
@@ -217,7 +217,11 @@
 
 #if SIZEOF_DOUBLE == 2*SIZEOF_LONG_INT
 
+#ifdef __amd64__
 INLINE_ONLY inline EXTERN void AlignGlobalForDouble( USES_REGS1 );
+#else
+inline EXTERN void AlignGlobalForDouble( USES_REGS1 );
+#endif
 
 #define DOUBLE_ALIGNED(ADDR) ((CELL)(ADDR) & 0x4)
 
