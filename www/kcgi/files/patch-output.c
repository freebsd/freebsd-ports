--- output.c.orig	2015-07-16 22:52:47 UTC
+++ output.c
@@ -17,9 +17,7 @@
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
-#ifdef __linux__
 #include <arpa/inet.h>
-#endif
 
 #include <assert.h>
 #include <stdarg.h>
@@ -27,6 +25,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #ifdef HAVE_ZLIB
 #include <zlib.h>
 #endif
