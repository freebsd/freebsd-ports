--- src/modules/rlm_otp/otp_state.c.orig	Wed Jan 25 13:35:45 2006
+++ src/modules/rlm_otp/otp_state.c	Wed Jan 25 15:02:47 2006
@@ -35,7 +35,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/socket.h>
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(bsdi) || defined(__OpenBSD__)
 #include <sys/un.h>
 #endif
 
