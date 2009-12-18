--- src/tsocks.c.orig	2009-11-08 14:35:11.000000000 +0200
+++ src/tsocks.c	2009-11-13 17:00:10.412574127 +0200
@@ -54,6 +54,13 @@
 #define _GNU_SOURCE
 #endif
 
+/* Required by some BSDs */
+#ifndef  MAP_ANONYMOUS
+#ifdef MAP_ANON
+#define MAP_ANONYMOUS MAP_ANON
+#endif
+#endif
+
 /* Global configuration variables */
 const char *progname = "libtorsocks";         /* Name used in err msgs    */
 
@@ -62,7 +69,6 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <dlfcn.h>
-#include <sys/types.h>
 #include <sys/socket.h>
 #include <string.h>
 #include <strings.h>
@@ -163,7 +169,7 @@
 void tsocks_init(void) {
 
 #define LOAD_ERROR(s,l) { \
-    char *error; \
+    const char *error; \
     error = dlerror(); \
     show_msg(l, "The symbol %s() was not found in any shared " \
                      "library. The error reported was: %s!\n", s, \
