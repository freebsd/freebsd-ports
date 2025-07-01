--- document-server-package/common/documentserver/bin/documentserver-update-securelink.sh.m4.orig	2023-06-20 13:50:40 UTC
+++ document-server-package/common/documentserver/bin/documentserver-update-securelink.sh.m4
@@ -1,24 +1,24 @@
 #!/bin/sh
 
-while [ "$1" != "" ]; do
+while [ $# -gt 0 ]; do
 	case $1 in
-
 		-s | --secure_link_secret )
 			if [ "$2" != "" ]; then
 				SECURE_LINK_SECRET=$2
 				shift
 			fi
+			shift
 		;;
 
                 -r | --restart )
-                        if [ "$2" != "" ]; then
+                        if [ "$2" = "true" ] || [ "$2" = "false" ]; then
                                 RESTART_CONDITION=$2
                                 shift
                         fi
+			shift
                 ;;
 
-
-		-? | -h | --help )
+		-h | --help )
 			echo "  Usage $0 [PARAMETER] [[PARAMETER], ...]"
 			echo "    Parameters:"
 			echo "      -s, --secure_link_secret               setting for secret string "
@@ -26,26 +26,21 @@ while [ "$1" != "" ]; do
 			echo
 			exit 0
 		;;
-
 	esac
 	shift
 done
 
-NGINX_CONF=/etc/M4_DS_PREFIX/nginx/ds.conf
-LOCAL_CONF=/etc/M4_DS_PREFIX/local.json
-JSON="/var/www/M4_DS_PREFIX/npm/json -q -f ${LOCAL_CONF}"
+NGINX_CONF=%%LOCALBASE%%/etc/M4_DS_PREFIX/nginx/ds.conf
+LOCAL_CONF=%%LOCALBASE%%/etc/M4_DS_PREFIX/local.json
+JSON="%%LOCALBASE%%/www/M4_DS_PREFIX/npm/json -q -f ${LOCAL_CONF}"
 
 SECURE_LINK_SECRET=${SECURE_LINK_SECRET:-$(tr -dc A-Za-z0-9 </dev/urandom | head -c 20)}
 
-sed "s,\(set \+\$secure_link_secret\).*,\1 "${SECURE_LINK_SECRET}";," -i ${NGINX_CONF}
-${JSON} -I -e 'this.storage={fs: {secretString: "'${SECURE_LINK_SECRET}'" }}' && chown ds:ds $LOCAL_CONF
+gsed "s,\(set \+\$secure_link_secret\).*,\1 ""${SECURE_LINK_SECRET}"";," -i ${NGINX_CONF}
+${JSON} -I -e 'this.storage={fs: {secretString: "'${SECURE_LINK_SECRET}'" }}' && chown onlyoffice:onlyoffice $LOCAL_CONF
 
 if [ "$RESTART_CONDITION" != "false" ]; then
-  if pgrep -x ""systemd"" >/dev/null; then
-    systemctl restart ds-docservice
-    systemctl restart ds-converter
-    systemctl reload nginx
-  elif pgrep -x ""supervisord"" >/dev/null; then
+  if pgrep -f "supervisord" >/dev/null; then
     supervisorctl restart ds:docservice
     supervisorctl restart ds:converter
     service nginx reload
