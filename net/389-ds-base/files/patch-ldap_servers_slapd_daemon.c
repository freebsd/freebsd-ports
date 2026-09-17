--- ldap/servers/slapd/daemon.c.orig	2026-09-07 12:14:21 UTC
+++ ldap/servers/slapd/daemon.c
@@ -811,6 +811,7 @@
         return;
 }
 
+#ifdef ENABLE_EPOLL
 char *epoll_event_flags_to_string(PRUint32 events)
 {
     static char buf[64];
@@ -856,6 +857,7 @@
     }
     return buf;
 }
+#endif /* ENABLE_EPOLL */
 
 #ifdef ENABLE_EPOLL
 static void
@@ -2607,6 +2609,16 @@
 static int
 lsan_ptrace_available(void)
 {
+#ifdef __FreeBSD__
+    /*
+     * The probe is Linux specific: the child PTRACE_ATTACHes to its own
+     * parent and then waitpid()s on it. Neither works here, FreeBSD spells
+     * the request PT_ATTACH and a child cannot wait for its parent. This
+     * only serves the LeakSanitizer in ASAN builds, so report it as
+     * unavailable.
+     */
+    return 0;
+#else
     pid_t child, ret;
     int status;
     int available = 0;
@@ -2641,6 +2653,7 @@
     }
 
     return available;
+#endif /* __FreeBSD__ */
 }
 
 void
@@ -3207,11 +3220,13 @@
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
