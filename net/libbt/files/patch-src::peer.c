--- src/peer.c	Wed Apr  7 06:14:44 2004
+++ src/peer.c.new	Tue Apr 13 19:29:01 2004
@@ -20,6 +20,7 @@
 #   endif
 #endif
 #include <sys/types.h>
+#include <sys/limits.h>
 #include <string.h>
 #ifdef HAVE_STRINGS_H
 #   include <strings.h>
