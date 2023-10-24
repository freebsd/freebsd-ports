--- src/3rdparty/PhysX/source/foundation/src/unix/PsUnixSocket.cpp.orig	2023-09-24 11:12:43 UTC
+++ src/3rdparty/PhysX/source/foundation/src/unix/PsUnixSocket.cpp
@@ -44,6 +44,9 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <unistd.h>
+#if PX_FREEBSD
+#include <netinet/in.h>
+#endif
 
 #define INVALID_SOCKET -1
 
