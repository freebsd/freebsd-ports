--- cl/src/update.c.orig	Tue May 14 00:45:54 2002
+++ cl/src/update.c	Tue May 14 00:47:01 2002
@@ -304,7 +304,7 @@
 
 	config_omf_dir[0] = '\0';
 
-	fid = fopen("/etc/scrollkeeper.conf", "r");
+	fid = fopen("%%PREFIX%%/etc/scrollkeeper.conf", "r");
 	if (fid == NULL) {
 		return;
 	}
