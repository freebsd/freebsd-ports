--- src/tsocks.c.orig	2009-02-12 15:59:50.000000000 +0200
+++ src/tsocks.c	2009-02-12 23:18:14.870533468 +0200
@@ -164,7 +164,7 @@
 void tsocks_init(void) {
 
 #define LOAD_ERROR(s,l) { \
-    char *error; \
+    const char *error; \
     error = dlerror(); \
     show_msg(l, "The symbol %s() was not found in any shared " \
                      "library. The error reported was: %s!\n", s, \
