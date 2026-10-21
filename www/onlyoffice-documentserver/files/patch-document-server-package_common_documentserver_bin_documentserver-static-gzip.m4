--- document-server-package/common/documentserver/bin/documentserver-static-gzip.m4.orig	2026-10-11 09:45:15 UTC
+++ document-server-package/common/documentserver/bin/documentserver-static-gzip.m4
@@ -1,18 +1,24 @@
-#!/bin/bash
+#!/bin/sh
 
-DIR="/var/www/M4_DS_PREFIX"
-NGINX_ONLYOFFICE_PATH="/etc/M4_DS_PREFIX/nginx"
+DIR="M4_DS_ROOT"
+NGINX_INCLUDES="M4_NGINX_CONF"
 
-cd ${DIR}
+cd ${DIR} || exit 1
 # Make gziped scripts
-find ./sdkjs ./web-apps ./sdkjs-plugins ./dictionaries -type f \( -name *.js -o -name *.json -o -name *.htm -o -name *.html -o -name *.css -o -name *.bin -o -name *.wasm -o -name *.dic -o -name *.aff -o -name *.svg \) -exec gzip -kf9 {} \;
+echo -n Generating gzipped scripts, please wait...
+find ./sdkjs ./web-apps ./sdkjs-plugins ./dictionaries -type f \( -name "*.js" -o -name "*.json" -o -name "*.htm" -o -name "*.html" -o -name "*.css" -o -name "*.bin" -o -name "*.wasm" -o -name "*.dic" -o -name "*.aff" -o -name "*.svg" \) -exec gzip -kf9 {} \;
+echo Done
 
 # Make gziped fonts
+echo -n Generating gzipped fonts, please wait...
 find ./fonts -type f ! -name "*.*" -exec gzip -kf9 {} \;
+echo Done
 
 # Turn on static gzip for nginx
-sed 's/#*\s*\(gzip_static\).*/\1 on;/g' \
-  -i ${NGINX_ONLYOFFICE_PATH}/includes/ds-docservice.conf
+sed -i '' -E 's/^([[:space:]]*)#*[[:space:]]*gzip_static.*/\1gzip_static on;/' \
+  ${NGINX_INCLUDES}/ds-docservice.conf
 
-# Reload nginx config
-[ $(pgrep -x ""systemd"" | wc -l) -gt 0 ] && systemctl reload nginx || service nginx reload
+# Reload nginx config only if nginx is actually running
+if service nginx onestatus >/dev/null 2>&1; then
+    service nginx onereload
+fi
