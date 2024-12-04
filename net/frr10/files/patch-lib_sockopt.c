--- lib/sockopt.c.orig	2024-11-12 16:20:46 UTC
+++ lib/sockopt.c
@@ -19,7 +19,7 @@
 #define HAVE_BSD_STRUCT_IP_MREQ_HACK
 #endif
 
-void setsockopt_so_recvbuf(int sock, int size)
+int setsockopt_so_recvbuf(int sock, int size)
 {
 	int orig_req = size;
 
@@ -34,9 +34,11 @@ void setsockopt_so_recvbuf(int sock, int size)
 		flog_err(EC_LIB_SOCKET,
 			 "%s: fd %d: SO_RCVBUF set to %d (requested %d)",
 			 __func__, sock, size, orig_req);
+
+	return size;
 }
 
-void setsockopt_so_sendbuf(const int sock, int size)
+int setsockopt_so_sendbuf(const int sock, int size)
 {
 	int orig_req = size;
 
@@ -51,6 +53,8 @@ void setsockopt_so_sendbuf(const int sock, int size)
 		flog_err(EC_LIB_SOCKET,
 			 "%s: fd %d: SO_SNDBUF set to %d (requested %d)",
 			 __func__, sock, size, orig_req);
+
+	return size;
 }
 
 int getsockopt_so_sendbuf(const int sock)
