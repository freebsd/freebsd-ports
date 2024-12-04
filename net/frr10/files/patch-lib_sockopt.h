--- lib/sockopt.h.orig	2024-11-12 16:20:46 UTC
+++ lib/sockopt.h
@@ -12,8 +12,8 @@ extern "C" {
 extern "C" {
 #endif
 
-extern void setsockopt_so_recvbuf(int sock, int size);
-extern void setsockopt_so_sendbuf(const int sock, int size);
+extern int setsockopt_so_recvbuf(int sock, int size);
+extern int setsockopt_so_sendbuf(const int sock, int size);
 extern int getsockopt_so_sendbuf(const int sock);
 extern int getsockopt_so_recvbuf(const int sock);
 
