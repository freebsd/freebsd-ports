--- internet.c.orig	Sat Sep 30 10:42:51 2000
+++ internet.c	Thu Feb 21 09:18:31 2008
@@ -77,17 +77,8 @@
 
 /* Look up the Internet name or IP number. */
 
-        if (! isdigit(hostname[0])) {
-            errno = 0;
-            host = gethostbyname(hostname);
-        } else {
-            if ((ipaddr = inet_addr(hostname)) == (unsigned long)-1)
-                fatal(0,"invalid IP number %s",hostname);
-            network_to_address(address,ipaddr);
-            errno = 0;
-            host = gethostbyaddr((void *)address,sizeof(struct in_addr),
-                AF_INET);
-        }
+	errno = 0;
+	host = gethostbyname(hostname);
 
 /* Now clear the timer and check the result. */

