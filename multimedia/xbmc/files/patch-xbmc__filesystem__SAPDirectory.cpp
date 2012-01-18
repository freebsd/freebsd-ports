--- ./xbmc/filesystem/SAPDirectory.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/filesystem/SAPDirectory.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -31,6 +31,9 @@
 #ifdef __APPLE__
 #include "OSXGNUReplacements.h" // strnlen
 #endif
+#ifdef __FreeBSD__
+#include "FreeBSDGNUReplacements.h"
+#endif
 
 #include <sys/socket.h>
 #include <netinet/in.h>
