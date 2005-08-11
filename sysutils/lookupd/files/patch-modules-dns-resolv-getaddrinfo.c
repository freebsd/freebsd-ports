--- modules/dns/resolv/getaddrinfo.c.orig	Fri Jul  2 15:28:07 2004
+++ modules/dns/resolv/getaddrinfo.c	Wed Aug 10 18:07:12 2005
@@ -339,6 +339,7 @@
 #define MATCH(x, y, w) \
 	((x) == (y) || (/*CONSTCOND*/(w) && ((x) == ANY || (y) == ANY)))
 
+#if __FreeBSD_version < 501000
 char *
 gai_strerror(ecode)
 	int ecode;
@@ -351,6 +352,7 @@
 	}
 	return "Unknown error";
 }
+#endif
 
 void
 freeaddrinfo(ai)
