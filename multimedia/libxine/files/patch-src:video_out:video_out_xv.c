--- src/video_out/video_out_xv.c.orig	Sun Aug 10 00:46:38 2003
+++ src/video_out/video_out_xv.c	Sun Aug 10 01:19:42 2003
@@ -45,7 +45,11 @@
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
 
 #if defined(__FreeBSD__)
