--- src/XFilePackage.cpp.orig	2010-08-24 07:46:45.000000000 +0000
+++ src/XFilePackage.cpp	2010-08-24 07:47:15.000000000 +0000
@@ -11,6 +11,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
+#include <sys/signal.h>
 
 #include "xfedefs.h"
 #include "icons.h"
