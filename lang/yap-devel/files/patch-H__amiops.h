--- ./H/amiops.h.orig	2012-06-30 16:53:59.000000000 -0300
+++ ./H/amiops.h	2013-08-13 18:37:02.000000000 -0300
@@ -102,10 +102,18 @@
 
 #if SIZEOF_DOUBLE == 2*SIZEOF_LONG_INT
 
+#ifdef __amd64__
 INLINE_ONLY EXTERN inline void
+#else
+EXTERN inline void
+#endif
 AlignGlobalForDouble( USES_REGS1 );
 
+#ifdef __amd64__
 INLINE_ONLY EXTERN inline void
+#else
+EXTERN inline void
+#endif
 AlignGlobalForDouble( USES_REGS1 )
 {
   /* Force Alignment for floats. Note that garbage collector may
