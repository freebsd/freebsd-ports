--- document-server-package/common/documentserver/bin/documentserver-generate-allfonts.m4.orig	2026-10-11 09:45:15 UTC
+++ document-server-package/common/documentserver/bin/documentserver-generate-allfonts.m4
@@ -9,9 +9,9 @@
     ONLYOFFICE_K8S_CONTAINER=$2
 fi
 
-DIR="/var/www/M4_DS_PREFIX"
+DIR="M4_DS_ROOT"
 
-export LD_LIBRARY_PATH=/var/www/M4_DS_PREFIX/server/FileConverter/bin:$LD_LIBRARY_PATH
+export LD_LIBRARY_PATH=M4_DS_ROOT/server/FileConverter/bin:$LD_LIBRARY_PATH
 
 # DS 9.5.0: registered as fontconfig source dir (09-documentserver-fonts.conf.m4, Bug 82565)
 command -v fc-cache >/dev/null 2>&1 && fc-cache -f "$DIR/../Data/custom-fonts" >/dev/null 2>&1
@@ -60,13 +60,6 @@
 
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
@@ -76,12 +69,8 @@
 
 #Restart web-site and converter
 if [ "$ONLYOFFICE_DATA_CONTAINER" != "true" ]; then
-  if pgrep -x ""systemd"" >/dev/null; then
-    systemctl restart ds-docservice
-    systemctl restart ds-converter
-  elif pgrep -x ""supervisord"" >/dev/null; then
+  if pgrep -f "supervisord" >/dev/null; then
     supervisorctl restart ds:docservice
-    supervisorctl restart ds:converter
   fi
   documentserver-flush-cache
   documentserver-static-gzip
