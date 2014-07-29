--- src/peer.c	Wed Apr  7 06:14:44 2004
+++ src/peer.c.new	Tue Apr 13 19:29:01 2004
@@ -20,6 +20,11 @@
 #   endif
 #endif
 #include <sys/types.h>
+#if __FreeBSD__ >= 5
+#include <sys/limits.h>
+#else
+#include <machine/limits.h>
+#endif
 #include <string.h>
 #ifdef HAVE_STRINGS_H
 #   include <strings.h>
