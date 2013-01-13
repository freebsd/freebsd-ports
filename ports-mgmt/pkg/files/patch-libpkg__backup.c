--- ./libpkg/backup.c.orig	2012-12-21 05:57:15.000000000 -0600
+++ ./libpkg/backup.c	2013-01-13 12:16:18.119457225 -0600
@@ -88,6 +88,7 @@
 	b = sqlite3_backup_init(dst, "main", src, "main");
 
 	elapsed = -1;
+	done = total = 0;
 	start = time(NULL);
 
 	do {
