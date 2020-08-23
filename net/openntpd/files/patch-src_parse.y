--- src/parse.y.orig	2020-08-23 20:10:30 UTC
+++ src/parse.y
@@ -57,7 +57,6 @@ int		 lgetc(int);
 int		 lungetc(int);
 int		 findeol(void);
 
-struct ntpd_conf		*conf;
 struct sockaddr_in		 query_addr4;
 struct sockaddr_in6		 query_addr6;
 
