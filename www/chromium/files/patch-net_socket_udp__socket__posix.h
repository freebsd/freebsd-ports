--- net/socket/udp_socket_posix.h.orig	2021-04-14 18:41:07 UTC
+++ net/socket/udp_socket_posix.h
@@ -35,7 +35,7 @@
 
 #if defined(__ANDROID__) && defined(__aarch64__)
 #define HAVE_SENDMMSG 1
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define HAVE_SENDMMSG 1
 #else
 #define HAVE_SENDMMSG 0
