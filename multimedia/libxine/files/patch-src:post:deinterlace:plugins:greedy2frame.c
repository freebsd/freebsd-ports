--- src/post/deinterlace/plugins/greedy2frame.c.orig	Sun Aug 10 01:30:49 2003
+++ src/post/deinterlace/plugins/greedy2frame.c	Sun Aug 10 01:31:11 2003
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
