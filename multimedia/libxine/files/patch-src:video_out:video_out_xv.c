--- src/video_out/video_out_xv.c.orig   Sun Dec 14 23:13:26 2003
+++ src/video_out/video_out_xv.c        Thu Feb  5 14:27:10 2004
@@ -47,13 +47,17 @@
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
 
+#include <sys/types.h>
 #if defined(__FreeBSD__)
 #include <machine/param.h>
 #endif
-#include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #include <sys/time.h>
