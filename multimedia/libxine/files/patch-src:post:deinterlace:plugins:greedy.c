--- src/post/deinterlace/plugins/greedy.c.orig	Sun Aug 10 01:21:43 2003
+++ src/post/deinterlace/plugins/greedy.c	Sun Aug 10 01:22:25 2003
@@ -23,7 +23,11 @@
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
