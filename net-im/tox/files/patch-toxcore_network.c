--- toxcore/network.c.orig	2022-04-18 18:12:07 UTC
+++ toxcore/network.c
@@ -1063,6 +1063,7 @@ Networking_Core *new_networking_ex(
      */
     int n = 1024 * 1024 * 2;
 
+#if !defined(__FreeBSD__)
     if (net_setsockopt(ns, temp->sock, SOL_SOCKET, SO_RCVBUF, &n, sizeof(n)) != 0) {
         LOGGER_ERROR(log, "failed to set socket option %d", SO_RCVBUF);
     }
@@ -1070,6 +1071,7 @@ Networking_Core *new_networking_ex(
     if (net_setsockopt(ns, temp->sock, SOL_SOCKET, SO_SNDBUF, &n, sizeof(n)) != 0) {
         LOGGER_ERROR(log, "failed to set socket option %d", SO_SNDBUF);
     }
+#endif
 
     /* Enable broadcast on socket */
     int broadcast = 1;
