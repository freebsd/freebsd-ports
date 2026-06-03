--- document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4.orig	2026-02-23 08:17:20 UTC
+++ document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4
@@ -9,7 +9,7 @@
     ONLYOFFICE_K8S_CONTAINER=$2
 fi
 
-DIR="/var/www/M4_DS_PREFIX"
+DIR="%%LOCALBASE%%/www/M4_DS_PREFIX"
 
 export LD_LIBRARY_PATH=/var/www/M4_DS_PREFIX/server/FileConverter/bin:$LD_LIBRARY_PATH
 
@@ -57,13 +57,6 @@
 
 echo Done
 
-# Setting user rights for files created in the previous steps
-if [ "${ONLYOFFICE_K8S_CONTAINER}" != "true" ]; then
-  chown -R ds:ds "$DIR/sdkjs"
-  chown -R ds:ds "$DIR/server/FileConverter/bin"
-  chown -R ds:ds "$DIR/fonts"
-fi
-
 #Remove gzipped files
 rm -f \
   $DIR/fonts/*.gz \
@@ -73,10 +66,7 @@
 
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
