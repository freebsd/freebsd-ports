--- lib/silccrypt/silcrng.c.orig	Sun Nov  4 07:59:11 2001
+++ lib/silccrypt/silcrng.c	Thu Nov  8 14:34:30 2001
@@ -28,12 +28,23 @@
 
 #include "silcincludes.h"
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if (defined(BSD) && (BSD >= 199103))
+# if defined(HAVE_GETSID) || defined(HAVE_GETPGID)
+#  include <unistd.h>
+# endif
+#else
+
 #ifdef HAVE_GETSID
 extern __pid_t getsid (__pid_t __pid);
 #endif
 
 #ifdef HAVE_GETPGID
 extern __pid_t getpgid (__pid_t __pid);
+#endif
 #endif
 
 #undef SILC_RNG_DEBUG
