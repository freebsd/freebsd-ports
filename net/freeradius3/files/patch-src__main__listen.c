--- src/main/listen.c.orig	2023-05-27 19:37:22.486268000 +0200
+++ src/main/listen.c	2023-05-27 19:47:35.685829000 +0200
@@ -55,7 +55,7 @@
 #ifdef WITH_TLS
 #include <netinet/tcp.h>
 
-#  ifdef __APPLE__
+#  if defined __APPLE__ || __FreeBSD__
 #    if !defined(SOL_TCP) && defined(IPPROTO_TCP)
 #      define SOL_TCP IPPROTO_TCP
 #    endif
