--- src/post/deinterlace/tvtime.c.orig	Sun Aug 10 01:34:07 2003
+++ src/post/deinterlace/tvtime.c	Sun Aug 10 01:34:32 2003
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
 #include "speedy.h"
 #include "deinterlace.h"
