--- src/main.cpp.orig	2010-12-26 16:04:06.000000000 +0300
+++ src/main.cpp	2010-12-26 16:05:49.000000000 +0300
@@ -60,6 +60,7 @@
 #include "stacktrace.h"
 #endif
 
+#include <csignal>
 #include <stdlib.h>
 #include "misc.h"
 #include "preferences.h"
