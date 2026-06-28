--- ldap/servers/slapd/daemon.c.orig	2026-06-28 09:01:40 UTC
+++ ldap/servers/slapd/daemon.c
@@ -805,6 +805,7 @@ disk_monitoring_thread(void *nothing __attribute__((un
         return;
 }
 
+#ifdef ENABLE_EPOLL
 char *epoll_event_flags_to_string(PRUint32 events)
 {
     static char buf[64];
@@ -850,6 +851,7 @@ char *epoll_event_flags_to_string(PRUint32 events)
     }
     return buf;
 }
+#endif /* ENABLE_EPOLL */
 
 #ifdef ENABLE_EPOLL
 static void
@@ -3115,11 +3117,13 @@ configure_pr_socket(PRFileDesc **pr_socket, int secure
     } /* else (!enable_nagle) */
 
     if (!local) {
+#ifdef TCP_LINGER2
         if (setsockopt(ns, IPPROTO_TCP, TCP_LINGER2, (void *)&fin_timeout, sizeof(fin_timeout)) == -1) {
             slapi_log_err(SLAPI_LOG_ERR,
                           "configure_pr_socket", "setsockopt(TCP_LINGER2) failed, error %d (%s)\n",
                           errno, strerror(errno));
         }
+#endif
 
         if (setsockopt(ns, IPPROTO_TCP, TCP_KEEPIDLE, (void *)&keepalive_time, sizeof(keepalive_time)) == -1) {
             slapi_log_err(SLAPI_LOG_ERR,
