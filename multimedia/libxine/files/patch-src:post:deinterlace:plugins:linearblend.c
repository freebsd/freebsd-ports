--- src/post/deinterlace/plugins/linearblend.c.orig	Sun Aug 10 01:26:05 2003
+++ src/post/deinterlace/plugins/linearblend.c	Sun Aug 10 01:26:34 2003
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
