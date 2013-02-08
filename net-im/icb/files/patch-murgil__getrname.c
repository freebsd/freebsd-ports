--- murgil/getrname.c.orig	2000-10-02 20:25:59.000000000 +0900
+++ murgil/getrname.c	2012-10-25 18:25:58.000000000 +0900
@@ -27,7 +27,7 @@
 {
 	struct hostent *host;
 	struct sockaddr_in rs;
-	int rs_size = sizeof(rs);
+	socklen_t rs_size = sizeof(rs);
 /* temporary hack */
 char *debug_c;
 long debug_l, inet_addr();
