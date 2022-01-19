--- document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4.orig	2022-01-19 20:22:54 UTC
+++ document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4
@@ -20,9 +20,9 @@ echo -n Generating AllFonts.js, please wait...
   --output-web="$DIR/fonts"\
   --use-system="true"
 
-chown -R ds:ds "$DIR/sdkjs"
-chown -R ds:ds "$DIR/server/FileConverter/bin"
-chown -R ds:ds "$DIR/fonts"
+chown -R onlyoffice:onlyoffice "$DIR/sdkjs"
+chown -R onlyoffice:onlyoffice "$DIR/server/FileConverter/bin"
+chown -R onlyoffice:onlyoffice "$DIR/fonts"
 
 echo Done
 
