--- src/connection.c.orig	2014-09-14 19:16:31 UTC
+++ src/connection.c
@@ -19,6 +19,10 @@
 #include <string.h>
 #include <time.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
+
 #include "util.h"
 #include "media.h"
 #include "driftnet.h"
