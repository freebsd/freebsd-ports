--- src/libusockets.h.orig	2020-04-08 20:24:31 UTC
+++ src/libusockets.h
@@ -230,7 +230,7 @@ WIN32_EXPORT void us_socket_remote_address(int ssl, st
 #if !defined(LIBUS_USE_EPOLL) && !defined(LIBUS_USE_LIBUV) && !defined(LIBUS_USE_GCD) && !defined(LIBUS_USE_KQUEUE)
 #if defined(_WIN32)
 #define LIBUS_USE_LIBUV
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #define LIBUS_USE_KQUEUE
 #else
 #define LIBUS_USE_EPOLL
