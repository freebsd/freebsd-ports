Fix for IPv6 only hosts, reported by Curtis Villamizar
http://lists.freebsd.org/pipermail/freebsd-apache/2012-August/002836.html
https://issues.apache.org/bugzilla/show_bug.cgi?id=53823

==================================================================
--- server/config.c.orig	2010-10-07 16:56:54 UTC
+++ server/config.c
@@ -1979,6 +1979,11 @@ static server_rec *init_server_config(pr
     /* NOT virtual host; don't match any real network interface */
     rv = apr_sockaddr_info_get(&s->addrs->host_addr,
                                NULL, APR_INET, 0, 0, p);
+#if APR_HAVE_IPV6
+    if (rv != APR_SUCCESS)
+	    rv = apr_sockaddr_info_get(&s->addrs->host_addr,
+			    NULL, APR_INET6, 0, 0, p);
+#endif    
     ap_assert(rv == APR_SUCCESS); /* otherwise: bug or no storage */
 
     s->addrs->host_port = 0; /* matches any port */
