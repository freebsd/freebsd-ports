--- src/network.c.orig	Thu Oct 14 18:03:49 2004
+++ src/network.c	Thu Dec 30 16:12:16 2004
@@ -125,7 +125,7 @@
     int retval;
 
     do { /* skip "Interrupted system call" errors */
-        retval=poll(fds->ufds, fds->nfds, 1000*timeout);
+        retval=poll(fds->ufds, fds->nfds, timeout < 0? INFTIM: 1000*timeout);
             /* no timeout -> main loop */
         if(timeout<0 && retval>0 && s_poll_canread(fds, signal_pipe[0]))
             signal_pipe_empty();
@@ -416,8 +416,12 @@
             return "Temporary failure in name resolution (EAI_AGAIN)";
         case EAI_FAIL:
             return "Non-recoverable failure in name resolution (EAI_FAIL)";
+#ifdef EAI_NODATA
+#if EAI_NODATA != EAI_NONAME
         case EAI_NODATA:
             return "No address associated with nodename (EAI_NODATA)";
+#endif
+#endif
         case EAI_FAMILY:
             return "ai_family not supported (EAI_FAMILY)";
         case EAI_SOCKTYPE:
@@ -561,11 +565,14 @@
 
 /* getnameinfo() version */
 char *s_ntop(char *text, SOCKADDR_UNION *addr) {
-    char host[20], port[6];
+    char host[IPLEN], port[6];
+    int err;
 
-    if(getnameinfo(&addr->sa, addr_len(*addr),
-            host, 20, port, 6, NI_NUMERICHOST|NI_NUMERICSERV)) {
-        sockerror("getnameinfo");
+    err = getnameinfo(&addr->sa, addr_len(*addr),
+            host, IPLEN, port, 6, NI_NUMERICHOST|NI_NUMERICSERV);
+    if (err) {
+        s_log(LOG_ERR, "Error resolving the specified address: %s",
+            s_gai_strerror(err));
         strcpy(text, "unresolvable IP");
         return text;
     }
