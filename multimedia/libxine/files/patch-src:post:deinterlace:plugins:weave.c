--- src/post/deinterlace/plugins/weave.c.orig	Sun Aug 10 01:29:19 2003
+++ src/post/deinterlace/plugins/weave.c	Sun Aug 10 01:29:36 2003
@@ -22,7 +22,11 @@
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
 #include "speedy.h"
 #include "deinterlace.h"
