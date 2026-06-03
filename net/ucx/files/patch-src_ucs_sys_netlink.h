--- src/ucs/sys/netlink.h.orig	2026-02-05 12:41:56 UTC
+++ src/ucs/sys/netlink.h
@@ -9,7 +9,12 @@
 
 #include <ucs/type/status.h>
 
+#if defined(__linux__)
 #include <linux/netlink.h>
+#else
+struct nlmsghdr;
+#endif
+#include <sys/socket.h>
 #include <netinet/in.h>
 
 BEGIN_C_DECLS
