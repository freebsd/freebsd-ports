--- mount_fusefs/mount_fusefs.c.orig	Tue Jun 19 09:35:22 2007
+++ mount_fusefs/mount_fusefs.c	Thu Dec 13 02:44:12 2007
@@ -70,6 +70,8 @@
 	{ "user_id=",            0, 0x00, 1 },
 	{ "group_id=",           0, 0x00, 1 },
 	{ "large_read",          0, 0x00, 1 },
+	/* "nonempty", just the first two chars are stripped off during parsing */
+	{ "nempty",              0, 0x00, 1 },
 	MOPT_STDOPTS,
 	MOPT_END
 };
@@ -469,7 +471,8 @@
 int
 init_backgrounded(void)
 {
-	int ibg, len;
+	int ibg;
+	size_t len;
 
 	len = sizeof(ibg);
 
