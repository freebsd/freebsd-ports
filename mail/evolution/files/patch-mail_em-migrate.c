--- mail/em-migrate.c.orig	Tue Dec 21 15:09:30 2004
+++ mail/em-migrate.c	Tue Dec 21 15:09:46 2004
@@ -1447,7 +1447,7 @@
 	ut.actime = st.st_atime;
 	ut.modtime = st.st_mtime;
 	utime (dest, &ut);
-	chmod (dest, st.st_mode);
+	chmod (dest, st.st_mode | S_IWUSR);
 	
 	return 0;
 	
