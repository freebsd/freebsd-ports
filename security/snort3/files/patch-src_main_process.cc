--- src/main/process.cc.orig	2024-05-17 14:59:20 UTC
+++ src/main/process.cc
@@ -60,6 +60,11 @@ extern "C" {
 #include <daq.h>
 }
 
+/* sighandler_t is GNU extension */
+#ifndef HAVE_SIGHANDLER_T
+typedef void (*sighandler_t) (int);
+#endif
+
 #include <csignal>
 #include <fstream>
 #include <iostream>
