--- qtsingleapplication/src/qtlocalpeer.cpp.orig	2013-09-12 13:40:34.269802688 +0400
+++ qtsingleapplication/src/qtlocalpeer.cpp	2013-09-12 13:41:07.606795170 +0400
@@ -50,6 +50,7 @@
 #endif
 #if defined(Q_OS_UNIX)
 #include <time.h>
+#include <unistd.h>
 #endif
 
 namespace QtLP_Private {
