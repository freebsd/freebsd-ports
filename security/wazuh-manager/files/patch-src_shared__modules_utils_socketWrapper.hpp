--- src/shared_modules/utils/socketWrapper.hpp	2025-09-23 06:59:40.000000000 -0700
+++ src/shared_modules/utils/socketWrapper.hpp	2025-10-11 22:55:35.847683000 -0700
@@ -28,6 +28,11 @@
 #include <thread>
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#define SO_RCVBUFFORCE SO_RCVBUF
+#define SO_SNDBUFFORCE SO_SNDBUF
+#endif
+
 #ifdef INVALID_SOCKET
 #undef INVALID_SOCKET
 #endif
