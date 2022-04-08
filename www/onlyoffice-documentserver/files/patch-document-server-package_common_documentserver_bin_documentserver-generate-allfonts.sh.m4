--- document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4.orig	2022-01-19 20:22:54 UTC
+++ document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4
@@ -20,10 +20,6 @@ echo -n Generating AllFonts.js, please wait...
   --output-web="$DIR/fonts"\
   --use-system="true"
 
-chown -R ds:ds "$DIR/sdkjs"
-chown -R ds:ds "$DIR/server/FileConverter/bin"
-chown -R ds:ds "$DIR/fonts"
-
 echo Done
 
 echo -n Generating presentation themes, please wait...
