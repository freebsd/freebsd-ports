--- src/post/deinterlace/plugins/linear.c.orig	Sun Aug 10 01:24:14 2003
+++ src/post/deinterlace/plugins/linear.c	Sun Aug 10 01:24:45 2003
@@ -20,7 +20,11 @@
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
