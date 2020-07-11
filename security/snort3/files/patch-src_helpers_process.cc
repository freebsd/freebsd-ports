--- src/helpers/process.cc.orig	2020-07-10 23:44:17 UTC
+++ src/helpers/process.cc
@@ -34,6 +34,11 @@
 #include <malloc.h>
 #endif
 
+/* sighandler_t is GNU extension */
+#ifndef HAVE_SIGHANDLER_T
+typedef void (*sighandler_t) (int);
+#endif
+
 #include <csignal>
 #include <iostream>
 
