--- dns.c.orig	2003-05-18 01:21:33 UTC
+++ dns.c
@@ -562,8 +562,13 @@ dns_resolve(char *ip, struct addrinfo **
         if (res != 0) {
                 fprintf(stderr, "%s: getaddrinfo(%s): %s\n", __func__,
 		    ip, gai_strerror(res));
+#ifdef EAI_NODATA
 		if (res != EAI_NODATA)
 			return (-1);
+#else
+		if (res != EAI_NONAME)
+			return (-1);
+#endif
 
 		/* Negative caching */
 		ai = NULL;
