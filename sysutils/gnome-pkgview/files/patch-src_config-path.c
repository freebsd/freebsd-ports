--- src/config-path.c.orig	Thu Nov 14 02:23:41 2002
+++ src/config-path.c	Thu Nov 14 02:29:54 2002
@@ -14,9 +14,7 @@
 	pkgs_found = 0;
       
        	/* parse the PKG_CONFIG_PATH env var, and add a terminator */
-	if ( getenv ("PKG_CONFIG_PATH") ) {
-		path = g_strconcat(getenv("PKG_CONFIG_PATH"),":DIRS_DONE",NULL);
-	}
+	path = "%%LOCALBASE%%/libdata/pkgconfig:%%X11BASE%%/libdata/pkgconfig:DIRS_DONE";
 
 	/* walk the PKG_CONFIG_PATH for other files */
 	if ( path ) {
