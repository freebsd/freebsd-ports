--- ./mpeg3tocutil.c.orig	Fri Jun  9 09:58:27 2006
+++ ./mpeg3tocutil.c	Sat Jul 22 18:02:04 2006
@@ -1415,8 +1415,8 @@
 
 int64_t mpeg3_calculate_source_date(char *path)
 {
-	struct stat64 ostat;
-	bzero(&ostat, sizeof(struct stat64));
-	stat64(path, &ostat);
+	struct stat ostat;
+	bzero(&ostat, sizeof(struct stat));
+	stat(path, &ostat);
 	return ostat.st_mtime;
 }
