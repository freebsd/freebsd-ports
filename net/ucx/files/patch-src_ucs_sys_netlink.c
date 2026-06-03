--- src/ucs/sys/netlink.c.orig	2026-02-05 12:41:56 UTC
+++ src/ucs/sys/netlink.c
@@ -8,6 +8,8 @@
 #include "config.h"
 #endif
 
+#if defined(__linux__)
+
 #include "netlink.h"
 
 #include <ucs/datastruct/khash.h>
@@ -310,3 +312,38 @@ int ucs_netlink_route_exists(int if_index, const struc
 
     return info.found;
 }
+#else
+
+#include "netlink.h"
+
+/*
+ * Netlink is Linux-specific. On non-Linux platforms (e.g., FreeBSD),
+ * UCX should build and run without netlink-based route checks.
+ */
+ucs_status_t
+ucs_netlink_send_request(int protocol, unsigned short nlmsg_type,
+                         unsigned short nlmsg_flags,
+                         const void *protocol_header, size_t header_length,
+                         ucs_netlink_parse_cb_t parse_cb, void *arg)
+{
+    (void)protocol;
+    (void)nlmsg_type;
+    (void)nlmsg_flags;
+    (void)protocol_header;
+    (void)header_length;
+    (void)parse_cb;
+    (void)arg;
+    return UCS_ERR_UNSUPPORTED;
+}
+
+int
+ucs_netlink_route_exists(int if_index, const struct sockaddr *sa_remote,
+                         int allow_default_gw)
+{
+    (void)if_index;
+    (void)sa_remote;
+    (void)allow_default_gw;
+    return 0;
+}
+
+#endif
