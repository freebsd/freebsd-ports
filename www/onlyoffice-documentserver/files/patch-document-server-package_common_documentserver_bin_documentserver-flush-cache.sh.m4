--- document-server-package/common/documentserver/bin/documentserver-flush-cache.sh.m4.orig	2025-07-18 12:53:25 UTC
+++ document-server-package/common/documentserver/bin/documentserver-flush-cache.sh.m4
@@ -24,18 +24,16 @@ done
 HASH=${HASH:-$(date +'%Y.%m.%d-%H%M' | openssl md5 | awk '{print $2}')}
 
 # Save the hash to a variable in the configuration file
-echo "set \$cache_tag \"$HASH\";" > /etc/nginx/includes/ds-cache.conf
+echo "set \$cache_tag \"$HASH\";" > %%ETCDIR%%/documentserver/nginx/includes/ds-cache.conf
 
-API_PATH="/var/www/M4_DS_PREFIX/web-apps/apps/api/documents/api.js"
+API_PATH="%%LOCALBASE%%/www/M4_DS_PREFIX/web-apps/apps/api/documents/api.js"
 cp -f ${API_PATH}.tpl ${API_PATH}
-sed -i "s/{{HASH_POSTFIX}}/${HASH}/g" ${API_PATH}
-chown ds:ds ${API_PATH}
+sed -i '' "s/{{HASH_POSTFIX}}/${HASH}/g" ${API_PATH}
+chown onlyoffice:onlyoffice ${API_PATH}
 rm -f ${API_PATH}.gz
 
 if [ "$RESTART_CONDITION" != "false" ]; then
-    if (pgrep -x "systemd" > /dev/null) && systemctl is-active --quiet nginx; then
-        systemctl reload nginx
-    elif service nginx status > /dev/null 2>&1; then
+    if service nginx status > /dev/null 2>&1; then
         service nginx reload
     fi
 fi
