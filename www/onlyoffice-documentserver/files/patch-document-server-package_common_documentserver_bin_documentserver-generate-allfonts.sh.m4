--- document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4.orig	2022-01-19 20:22:54 UTC
+++ document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4
@@ -49,11 +49,6 @@ echo Done
 
 echo Done
 
-# Setting user rights for files created in the previous steps
-chown -R ds:ds "$DIR/sdkjs"
-chown -R ds:ds "$DIR/server/FileConverter/bin"
-chown -R ds:ds "$DIR/fonts"
-
 #Remove gzipped files
 rm -f \
   $DIR/fonts/*.gz \
