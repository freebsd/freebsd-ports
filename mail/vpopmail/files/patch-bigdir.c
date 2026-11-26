--- bigdir.c.orig	2005-01-01 00:00:00.000000000 +0000
+++ bigdir.c	2005-01-01 00:00:00.000000000 +0000
@@ -50,7 +50,7 @@
 int dec_dir_control(char *domain, uid_t uid, gid_t gid)
 {
 	open_big_dir(domain, uid, gid);
-	--vdir.cur_users;
+	if (vdir.cur_users > 0) --vdir.cur_users;
 	close_big_dir(domain, uid, gid);
 	return(0);
 }
