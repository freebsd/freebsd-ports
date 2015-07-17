--- child.c.orig	2015-07-16 22:52:47 UTC
+++ child.c
@@ -17,9 +17,7 @@
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
-#ifdef __linux__
 #include <arpa/inet.h>
-#endif
 
 #include <assert.h>
 #include <ctype.h>
