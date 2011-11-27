--- readnews/readnews.c.orig	1995-04-28 03:12:21.000000000 +0200
+++ readnews/readnews.c	2011-05-12 16:07:47.000000000 +0200
@@ -33,7 +33,7 @@
 
 active *alist;		/* internal active list */
 
-long now;		/* current time */
+time_t now;		/* current time */
 bool interrupt;		/* if interrupt hit */
 char *newsdir;		/* %news */
 bool su;		/* if super user (not used) */
@@ -950,7 +950,7 @@
 	register char *cp;
 	register FILE	*sf;
 	register char *aname;
-	long then;
+	time_t then;
 	extern char *getenv();
 
 	if (!*s) {
