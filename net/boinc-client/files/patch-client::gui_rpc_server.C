--- client/gui_rpc_server.C.orig	Mon Sep 27 15:07:29 2004
+++ client/gui_rpc_server.C	Thu Dec  2 20:59:58 2004
@@ -47,12 +47,10 @@
 
 #if defined(_WIN32)
 typedef int socklen_t;
-#elif defined ( __APPLE__)
+#elif defined(__APPLE__)
 typedef int32_t socklen_t;
-#elif !GETSOCKOPT_SOCKLEN_T
-#ifndef socklen_t
+#elif !defined(GETSOCKOPT_SOCKLEN_T) && !defined(_SOCKLEN_T_DECLARED) && !defined(socklen_t)
 typedef size_t socklen_t;
-#endif
 #endif
 
 static void boinc_close_socket(int sock) {
