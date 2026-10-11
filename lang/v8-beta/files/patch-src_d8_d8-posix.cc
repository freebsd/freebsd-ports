--- src/d8/d8-posix.cc.orig	2026-04-02 12:37:23 UTC
+++ src/d8/d8-posix.cc
@@ -7,6 +7,8 @@
 
 #include "src/d8/d8.h"
 
+#include <sys/types.h>
+#include <netinet/in.h>
 #ifndef V8_OS_ZOS
 #include <netinet/ip.h>
 #endif
@@ -17,7 +19,6 @@
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
 
