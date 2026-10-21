--- document-server-package/common/documentserver/bin/documentserver-flush-cache.m4.orig	2026-10-11 09:45:15 UTC
+++ document-server-package/common/documentserver/bin/documentserver-flush-cache.m4
@@ -39,18 +39,16 @@
 HASH=${HASH:-$(date +'%Y.%m.%d-%H%M' | openssl md5 | awk '{print $2}')}
 
 # Save the hash to a variable in the configuration file
-echo "set \$cache_tag \"$HASH\";" > /etc/nginx/includes/ds-cache.conf
+echo "set \$cache_tag \"$HASH\";" > M4_NGINX_CONF/ds-cache.conf
 
-API_PATH="/var/www/M4_DS_PREFIX/web-apps/apps/api/documents/api.js"
+API_PATH="M4_DS_ROOT/web-apps/apps/api/documents/api.js"
 cp -f ${API_PATH}.tpl ${API_PATH}
-sed -i "s/{{HASH_POSTFIX}}/${HASH}/g" ${API_PATH}
-chown ds:ds ${API_PATH}
+sed -i '' "s/{{HASH_POSTFIX}}/${HASH}/g" ${API_PATH}
+chown M4_DS_USER:M4_DS_GROUP ${API_PATH}
 rm -f ${API_PATH}.gz
 
 if [ "$RESTART_CONDITION" != "false" ]; then
-    if (pgrep -x "systemd" > /dev/null) && systemctl is-active --quiet nginx; then
-        systemctl reload nginx
-    elif service nginx status > /dev/null 2>&1; then
-        service nginx reload
+    if service nginx onestatus > /dev/null 2>&1; then
+        service nginx onereload
     fi
 fi
