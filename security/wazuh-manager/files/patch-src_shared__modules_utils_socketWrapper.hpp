--- src/shared_modules/utils/socketWrapper.hpp.orig	2024-10-20 21:04:00.880393000 -0700
+++ src/shared_modules/utils/socketWrapper.hpp	2024-10-20 21:07:41.992525000 -0700
@@ -28,6 +28,11 @@
 #include <thread>
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#define SO_RCVBUFFORCE SO_RCVBUF
+#define SO_SNDBUFFORCE SO_SNDBUF
+#endif
+
 constexpr auto INVALID_SOCKET {-1};
 constexpr auto SOCKET_ERROR {-1};
 using PacketFieldType = uint32_t;
