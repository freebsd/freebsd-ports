--- src/uct/tcp/tcp_base.c.orig	2026-02-04 09:52:46 UTC
+++ src/uct/tcp/tcp_base.c
@@ -15,8 +15,12 @@ ucs_status_t ucs_tcp_base_set_syn_cnt(int fd, int tcp_
 ucs_status_t ucs_tcp_base_set_syn_cnt(int fd, int tcp_syn_cnt)
 {
     if (tcp_syn_cnt != UCS_ULUNITS_AUTO) {
+#if defined(__linux__)
         ucs_socket_setopt(fd, IPPROTO_TCP, TCP_SYNCNT, (const void*)&tcp_syn_cnt,
                           sizeof(int));
+#else
+        (void)fd;
+#endif
     }
 
     /* return UCS_OK anyway since setting TCP_SYNCNT is done on best effort */
