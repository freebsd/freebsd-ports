--- srclib/apr/network_io/unix/sockaddr.c.orig	Tue Jul 13 09:08:03 2004
+++ srclib/apr/network_io/unix/sockaddr.c	Tue Jul 13 09:08:46 2004
@@ -612,6 +612,7 @@
         struct sockaddr_in tmpsa;
         tmpsa.sin_family = AF_INET;
         tmpsa.sin_addr.s_addr = ((apr_uint32_t *)sockaddr->ipaddr_ptr)[3];
+        tmpsa.sin_len = sizeof(tmpsa);
 
         rc = getnameinfo((const struct sockaddr *)&tmpsa, sizeof(tmpsa),
                          tmphostname, sizeof(tmphostname), NULL, 0,
