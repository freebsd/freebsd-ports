--- src/NewsCache.cc.orig	Mon Jan 19 13:52:04 2004
+++ src/NewsCache.cc	Mon Jan 19 13:52:55 2004
@@ -24,7 +24,9 @@
  */
 #include "config.h"
 
+#ifndef __FreeBSD__
 #include <crypt.h>
+#endif
 #include <ctype.h>
 #include <unistd.h>
 #include <string.h>
