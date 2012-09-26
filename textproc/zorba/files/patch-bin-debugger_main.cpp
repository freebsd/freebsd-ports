--- bin/debugger/main.cpp.orig	2012-06-21 11:19:43.000000000 +0200
+++ bin/debugger/main.cpp	2012-06-21 11:19:27.000000000 +0200
@@ -22,6 +22,8 @@
 #include <unistd.h>
 #endif
 
+#include <signal.h>
+
 #include <vector>
 
 #include <zorba/config.h>
