--- document-server-package/common/documentserver/bin/documentserver-static-gzip.sh.m4.orig	2023-06-20 13:45:17 UTC
+++ document-server-package/common/documentserver/bin/documentserver-static-gzip.sh.m4
@@ -1,18 +1,18 @@
-#!/bin/bash
+#!/bin/sh
 
-DIR="/var/www/M4_DS_PREFIX"
-NGINX_ONLYOFFICE_PATH="/etc/M4_DS_PREFIX/nginx"
+DIR="%%LOCALBASE%%/www/M4_DS_PREFIX"
+NGINX_ONLYOFFICE_PATH="%%LOCALBASE%%/etc/M4_DS_PREFIX/nginx"
 
-cd ${DIR}
+cd ${DIR} || exit 1
 # Make gziped scripts
-find ./sdkjs ./web-apps ./sdkjs-plugins ./dictionaries -type f \( -name *.js -o -name *.json -o -name *.htm -o -name *.html -o -name *.css -o -name *.bin -o -name *.wasm -o -name *.dic -o -name *.aff -o -name *.svg \) -exec gzip -kf9 {} \;
+find ./sdkjs ./web-apps ./sdkjs-plugins ./dictionaries -type f \( -name "*.js" -o -name "*.json" -o -name "*.htm" -o -name "*.html" -o -name "*.css" -o -name "*.bin" -o -name "*.wasm" -o -name "*.dic" -o -name "*.aff" -o -name "*.svg" \) -exec gzip -kf9 {} \;
 
 # Make gziped fonts
 find ./fonts -type f ! -name "*.*" -exec gzip -kf9 {} \;
 
 # Turn on static gzip for nginx
-sed 's/#*\s*\(gzip_static\).*/\1 on;/g' \
+gsed 's/#*\s*\(gzip_static\).*/\1 on;/g' \
   -i ${NGINX_ONLYOFFICE_PATH}/includes/ds-docservice.conf
 
 # Reload nginx config
-[ $(pgrep -x ""systemd"" | wc -l) -gt 0 ] && systemctl reload nginx || service nginx reload
+service nginx reload
