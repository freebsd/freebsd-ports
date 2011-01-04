Description: Allow transparent proxying using IP_BINDANY.
Forwarded: yes
Author: Peter Pentchev <roam@FreeBSD.org>,
	Jason Helfman <jhelfman@experts-exchange.com>
Last-Updated: 2011-01-04

--- src/client.c.orig
+++ src/client.c
@@ -1034,15 +1034,16 @@
 static void local_bind(CLI *c) {
     SOCKADDR_UNION addr;
 
-#ifdef IP_TRANSPARENT
+#ifdef STUNNEL_TRANSPARENT
     int on=1;
     if(c->opt->option.transparent) {
-        if(setsockopt(c->fd, SOL_IP, IP_TRANSPARENT, &on, sizeof on))
-            sockerror("setsockopt IP_TRANSPARENT");
+        if(setsockopt(c->fd, STUNNEL_TRANSPARENT_LEVEL,
+	   STUNNEL_TRANSPARENT, &on, sizeof on))
+            sockerror("setsockopt " STUNNEL_TRANSPARENT_NAME);
         /* ignore the error to retain Linux 2.2 compatibility */
         /* the error will be handled by bind(), anyway */
     }
-#endif /* IP_TRANSPARENT */
+#endif /* STUNNEL_TRANSPARENT */
 
     memcpy(&addr, &c->bind_addr.addr[0], sizeof addr);
     if(ntohs(addr.in.sin_port)>=1024) { /* security check */
