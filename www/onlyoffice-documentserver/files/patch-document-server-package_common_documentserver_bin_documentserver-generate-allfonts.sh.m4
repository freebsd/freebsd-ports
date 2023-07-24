--- document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4.orig	2023-06-20 13:47:11 UTC
+++ document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4
@@ -5,7 +5,7 @@ fi
     ONLYOFFICE_DATA_CONTAINER=$1
 fi
 
-DIR="/var/www/M4_DS_PREFIX"
+DIR="%%LOCALBASE%%/www/M4_DS_PREFIX"
 
 #Start generate AllFonts.js, font thumbnails and font_selection.bin
 echo -n Generating AllFonts.js, please wait...
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
@@ -62,10 +57,7 @@ if [ "$ONLYOFFICE_DATA_CONTAINER" != "true" ]; then
 
 #Restart web-site and converter
 if [ "$ONLYOFFICE_DATA_CONTAINER" != "true" ]; then
-  if pgrep -x ""systemd"" >/dev/null; then
-    systemctl restart ds-docservice
-    systemctl restart ds-converter
-  elif pgrep -x ""supervisord"" >/dev/null; then
+  if pgrep -f "supervisord" >/dev/null; then
     supervisorctl restart ds:docservice
     supervisorctl restart ds:converter
   fi
