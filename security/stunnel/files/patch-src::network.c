--- src/network.c.orig	Mon Jan  3 09:16:45 2005
+++ src/network.c	Mon Jan  3 09:17:49 2005
@@ -488,10 +488,13 @@
 
 char *s_ntop(char *text, SOCKADDR_UNION *addr) {
     char host[IPLEN-6], port[6];
+    int err;
 
-    if(getnameinfo(&addr->sa, addr_len(*addr),
-            host, IPLEN-6, port, 6, NI_NUMERICHOST|NI_NUMERICSERV)) {
-        sockerror("getnameinfo");
+    err = getnameinfo(&addr->sa, addr_len(*addr),
+            host, IPLEN-6, port, 6, NI_NUMERICHOST|NI_NUMERICSERV);
+    if (err) {
+        s_log(LOG_ERR, "Error resolving the specified address: %s",
+            s_gai_strerror(err));
         strcpy(text, "unresolvable IP");
         return text;
     }
