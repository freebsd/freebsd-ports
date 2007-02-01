--- ./src/watchdog/EmailReporter.cpp.orig	Sat Dec 30 14:24:12 2006
+++ ./src/watchdog/EmailReporter.cpp	Sat Dec 30 14:24:35 2006
@@ -10,7 +10,11 @@
 //////////////////////////////////////////////////////////////////////////////
 
 // SYSTEM INCLUDES
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 // APPLICATION INCLUDES
 #include "os/OsConnectionSocket.h"
