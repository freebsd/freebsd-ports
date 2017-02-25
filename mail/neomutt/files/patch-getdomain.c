--- getdomain.c.orig	2017-02-25 01:23:52 UTC
+++ getdomain.c
@@ -67,7 +67,7 @@ int getdnsdomainname (char *d, size_t le
 
 #else /* !HAVE_GETADDRINFO_A */
 
-  getaddrinfo(node, NULL, &hints, &h)
+  getaddrinfo(node, NULL, &hints, &h);
 
 #endif
 
