--- bin/debugger/main.cpp.orig	2012-10-04 00:35:17.000000000 +0200
+++ bin/debugger/main.cpp	2014-09-11 15:46:51.000000000 +0200
@@ -22,6 +22,9 @@
 #include <unistd.h>
 #endif
 
+#include <signal.h>
+#include <stdlib.h>
+
 #include <vector>
 
 #include <zorba/config.h>
