--- maildir/maildirquota.c.orig	Fri Jun 18 23:27:53 2004
+++ maildir/maildirquota.c	Fri Jun 18 23:45:01 2004
@@ -748,7 +748,7 @@
 char	*p;
 DIR	*dirp;
 struct dirent *de;
-off_t	s;
+unsigned long s;
 
 	if (stat(dir, &stat_buf))	return (0);	/* Ignore */
 	if (stat_buf.st_mtime > *dirstamp)	*dirstamp=stat_buf.st_mtime;
