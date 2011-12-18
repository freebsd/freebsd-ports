--- xbmc/filesystem/SAPDirectory.cpp.orig
+++ xbmc/filesystem/SAPDirectory.cpp
@@ -31,6 +31,9 @@
 #ifdef __APPLE__
 #include "OSXGNUReplacements.h" // strnlen
 #endif
+#ifdef __FreeBSD__
+#include "FreeBSDGNUReplacements.h" // strnlen
+#endif
 
 #include <sys/socket.h>
 #include <netinet/in.h>
