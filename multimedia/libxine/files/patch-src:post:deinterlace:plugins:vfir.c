--- src/post/deinterlace/plugins/vfir.c.orig	Sun Aug 10 01:27:59 2003
+++ src/post/deinterlace/plugins/vfir.c	Sun Aug 10 01:28:18 2003
@@ -25,7 +25,11 @@
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
 
 #ifdef HAVE_CONFIG_H
