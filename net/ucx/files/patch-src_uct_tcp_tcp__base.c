--- src/uct/tcp/tcp_base.c.orig	2026-09-13 01:26:42 UTC
+++ src/uct/tcp/tcp_base.c
@@ -17,9 +17,15 @@ ucs_status_t ucs_tcp_base_set_syn_cnt(int fd, int tcp_
 ucs_status_t ucs_tcp_base_set_syn_cnt(int fd, int tcp_syn_cnt)
 {
     if (tcp_syn_cnt != UCS_ULUNITS_AUTO) {
+#ifdef TCP_SYNCNT
         return ucs_socket_setopt(fd, IPPROTO_TCP, TCP_SYNCNT,
                                  (const void*)&tcp_syn_cnt,
                                  sizeof(tcp_syn_cnt));
+#else
+        (void)fd;
+        (void)tcp_syn_cnt;
+        return UCS_OK;
+#endif
     }
 
     return UCS_OK;
@@ -54,7 +60,8 @@ ucs_status_t ucs_tcp_base_set_user_timeout(int fd, ucs
                              (const void*)&user_timeout_ms,
                              sizeof(user_timeout_ms));
 #else
-    ucs_error("TCP_USER_TIMEOUT is not supported");
-    return UCS_ERR_UNSUPPORTED;
+    (void)fd;
+    (void)user_timeout;
+    return UCS_OK;
 #endif
 }
