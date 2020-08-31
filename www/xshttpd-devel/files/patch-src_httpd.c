--- src/httpd.c.orig	2015-09-05 20:44:28 UTC
+++ src/httpd.c
@@ -84,6 +84,7 @@ static	char	referer[MYBUFSIZ], orig[MYBUFSIZ];
 static	char	*startparams, *message503;
 struct	session		session;
 struct	env		env;
+struct	socket_config	*cursock;
 
 /* Prototypes */
 
