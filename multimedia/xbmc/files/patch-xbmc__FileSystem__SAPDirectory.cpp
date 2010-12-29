Index: xbmc/FileSystem/SAPDirectory.cpp
===================================================================
--- xbmc/FileSystem/SAPDirectory.cpp	(revision 35575)
+++ xbmc/FileSystem/SAPDirectory.cpp	(working copy)
@@ -30,6 +30,9 @@
 #ifdef __APPLE__
 #include "OSXGNUReplacements.h" // strnlen
 #endif
+#ifdef __FreeBSD__
+#include "FreeBSDGNUReplacements.h" // strnlen
+#endif
 #ifdef _MSC_VER
 #include <Ws2tcpip.h>
 #else
