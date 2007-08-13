--- mount_fusefs/mount_fusefs.c	Sat Jul 14 13:12:09 2007
+++ mount_fusefs/mount_fusefs.c	Sat Jul 14 13:12:09 2007
@@ -469,7 +469,8 @@ showversion(void)
 int
 init_backgrounded(void)
 {
-	int ibg, len;
+	int ibg;
+	size_t len;
 
 	len = sizeof(ibg);
