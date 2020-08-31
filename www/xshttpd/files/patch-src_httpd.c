--- src/httpd.c.orig	2009-01-10 22:52:29 UTC
+++ src/httpd.c
@@ -90,6 +90,8 @@ static	char	referer[MYBUFSIZ], orig[MYBUFSIZ];
 static	char	*startparams, *message503;
 struct	session		session;
 struct	env		env;
+struct	socket_config	*cursock;
+
 #define CLEANENV do { \
 	memset(&env, 0, sizeof(struct env));\
 	MALLOC(environ, char *, 1);\
