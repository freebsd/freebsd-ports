--- src/video_out/video_out_xv.c.orig	Wed Apr 28 01:56:34 2004
+++ src/video_out/video_out_xv.c	Sun May  9 21:51:48 2004
@@ -47,7 +47,11 @@
 #if defined (__SVR4) && defined (__sun)
 # include <sys/int_types.h>
 #else
-# include <stdint.h>
+# if defined(HAVE_STDINT_H)
+#  include <stdint.h>
+# else
+#  include <inttypes.h>
+# endif
 #endif
 
 #include <sys/types.h>
