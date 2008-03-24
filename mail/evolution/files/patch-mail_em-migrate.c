--- mail/em-migrate.c.orig	2007-12-15 16:58:56.000000000 +0100
+++ mail/em-migrate.c	2007-12-21 16:17:32.000000000 +0100
@@ -1493,7 +1493,7 @@
 	ut.actime = st.st_atime;
 	ut.modtime = st.st_mtime;
 	utime (dest, &ut);
-	chmod (dest, st.st_mode);
+	chmod (dest, st.st_mode | S_IWUSR);
 
 	return 0;
 
