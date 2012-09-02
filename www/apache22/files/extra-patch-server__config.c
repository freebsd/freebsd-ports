--- ./server/config.c.orig	2012-08-13 21:15:02.000000000 +0200
+++ ./server/config.c	2012-08-13 21:22:15.000000000 +0200
@@ -1979,6 +1979,11 @@
     /* NOT virtual host; don't match any real network interface */
     rv = apr_sockaddr_info_get(&s->addrs->host_addr,
                                NULL, APR_INET, 0, 0, p);
+    /* Support for IPv6 only, reported by Curtis Villamizar <curtis@occnc.com> */
+    /* http://lists.freebsd.org/pipermail/freebsd-apache/2012-August/002836.html */
+    if (rv != APR_SUCCESS)
+	    rv = apr_sockaddr_info_get(&s->addrs->host_addr,
+			    NULL, APR_INET6, 0, 0, p);
     ap_assert(rv == APR_SUCCESS); /* otherwise: bug or no storage */
 
     s->addrs->host_port = 0; /* matches any port */
