--- src/network.c.orig	Mon Dec 27 15:30:04 2004
+++ src/network.c	Mon Dec 27 15:30:07 2004
@@ -125,7 +125,7 @@
     int retval;
 
     do { /* skip "Interrupted system call" errors */
-        retval=poll(fds->ufds, fds->nfds, 1000*timeout);
+        retval=poll(fds->ufds, fds->nfds, timeout < 0? INFTIM: 1000*timeout);
             /* no timeout -> main loop */
         if(timeout<0 && retval>0 && s_poll_canread(fds, signal_pipe[0]))
             signal_pipe_empty();
@@ -416,8 +416,10 @@
             return "Temporary failure in name resolution (EAI_AGAIN)";
         case EAI_FAIL:
             return "Non-recoverable failure in name resolution (EAI_FAIL)";
+#ifdef EAI_NODATA
         case EAI_NODATA:
             return "No address associated with nodename (EAI_NODATA)";
+#endif
         case EAI_FAMILY:
             return "ai_family not supported (EAI_FAMILY)";
         case EAI_SOCKTYPE:
@@ -562,10 +564,13 @@
 /* getnameinfo() version */
 char *s_ntop(char *text, SOCKADDR_UNION *addr) {
     char host[20], port[6];
+    int err;
 
-    if(getnameinfo(&addr->sa, addr_len(*addr),
-            host, 20, port, 6, NI_NUMERICHOST|NI_NUMERICSERV)) {
-        sockerror("getnameinfo");
+    err = getnameinfo(&addr->sa, addr_len(*addr),
+            host, 20, port, 6, NI_NUMERICHOST|NI_NUMERICSERV);
+    if (err) {
+        s_log(LOG_ERR, "Error resolving the specified address: %s",
+            s_gai_strerror(err));
         strcpy(text, "unresolvable IP");
         return text;
     }
