--- src/mozilla/TOCProtocolHandler.cpp.orig	Sun Jun 16 14:02:36 2002
+++ src/mozilla/TOCProtocolHandler.cpp	Sun Jun 16 14:11:48 2002
@@ -400,7 +400,7 @@
 	nsresult rv;
 
 	struct dirent **namelist;
-	int n = scandir (SHARE_DIR"/../gnome/help", &namelist, select,
+	int n = scandir (SHARE_DIR"/../gnome/help", &namelist, ((int(*)(struct dirent *))select),
 			 alphasort);
 	if (n<0) return NS_ERROR_FAILURE;
 
