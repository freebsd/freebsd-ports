--- lib/silccrypt/silcrng.c.orig	Wed Nov 14 12:44:05 2001
+++ lib/silccrypt/silcrng.c	Wed Nov 14 22:19:57 2001
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
 extern pid_t getsid (pid_t __pid);
 #endif
 
 #ifdef HAVE_GETPGID
 extern pid_t getpgid (pid_t __pid);
+#endif
 #endif
 
 #undef SILC_RNG_DEBUG
