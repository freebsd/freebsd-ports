--- apps/ocspcheck/ocspcheck.c.orig	2017-01-27 11:30:47 UTC
+++ apps/ocspcheck/ocspcheck.c
@@ -17,6 +17,7 @@
 #include <arpa/inet.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
+#include <netinet/in.h>
 
 #include <err.h>
 #include <fcntl.h>
@@ -76,7 +77,9 @@ host_dns(const char *s, struct addr vec[
 	error = getaddrinfo(s, NULL, &hints, &res0);
 
 	if (error == EAI_AGAIN ||
+#ifdef EAI_NODATA
 	    error == EAI_NODATA ||
+#endif
 	    error == EAI_NONAME)
 		return(0);
 
