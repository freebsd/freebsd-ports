--- src/ucs/sys/sock.c.orig	2026-05-06 13:47:14 UTC
+++ src/ucs/sys/sock.c
@@ -20,7 +20,10 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/sysctl.h>
 #include <ifaddrs.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <unistd.h>
 #include <errno.h>
 #include <string.h>
@@ -517,6 +520,16 @@ int ucs_socket_max_conn()
 int ucs_socket_max_conn()
 {
     static long somaxconn_val = 0;
+
+#if defined(__FreeBSD__)
+    if (!somaxconn_val) {
+        int val;
+        size_t len = sizeof(val);
+        if (sysctlbyname("kern.ipc.somaxconn", &val, &len, NULL, 0) == 0) {
+            somaxconn_val = val;
+        }
+    }
+#endif
 
     if (somaxconn_val ||
         (ucs_read_file_number(&somaxconn_val, 1,
