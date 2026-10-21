--- document-server-package/common/documentserver/bin/documentserver-update-securelink.m4.orig	2026-10-11 09:45:15 UTC
+++ document-server-package/common/documentserver/bin/documentserver-update-securelink.m4
@@ -1,8 +1,11 @@
 #!/bin/sh
 
-NGINX_CONF=/etc/M4_DS_PREFIX/nginx/ds.conf
+NGINX_HTTP_CONF=M4_DS_CONF/nginx/ds.conf
+NGINX_SSL_CONF=M4_DS_CONF/nginx/ds-ssl.conf
+LOCAL_CONF=M4_DS_CONF/local.json
+JSON="M4_DS_ROOT/npm/json -q -f ${LOCAL_CONF}"
 
-while [ "$1" != "" ]; do
+while [ $# -gt 0 ]; do
 	case $1 in
 
 		-s | --secure_link_secret )
@@ -10,28 +13,33 @@
 				SECURE_LINK_SECRET=$2
 				shift
 			fi
+			shift
 		;;
 
-                -r | --restart )
-                        if [ "$2" != "" ]; then
-                                RESTART_CONDITION=$2
-                                shift
-                        fi
-                ;;
+		-r | --restart )
+			if [ "$2" = "true" ] || [ "$2" = "false" ]; then
+				RESTART_CONDITION=$2
+				shift
+			fi
+			shift
+		;;
 
 		--generate-secret )
-			if grep -q secure_link_secret ${NGINX_CONF} && ! grep -Eq 'set \$secure_link_secret "?verysecretstring"?;' ${NGINX_CONF}; then
-				exit 0
-			fi
+			for conf in "${NGINX_HTTP_CONF}" "${NGINX_SSL_CONF}"; do
+				if [ -f "${conf}" ]; then
+					if grep -q secure_link_secret "${conf}" && ! grep -Eq 'set \$secure_link_secret "?verysecretstring"?;' "${conf}"; then
+						exit 0
+					fi
+				fi
+			done
 		;;
 
-
-		-? | -h | --help )
+		-h | --help )
 			echo "  Usage $0 [PARAMETER] [[PARAMETER], ...]"
 			echo "    Parameters:"
 			echo "      -s, --secure_link_secret               setting for secret string "
 			echo "      --generate-secret                      generate a random secret if missing or default"
-			echo "      -?, -h, --help                    this help"
+			echo "      -h, --help                        this help"
 			echo
 			exit 0
 		;;
@@ -40,27 +48,36 @@
 	shift
 done
 
-LOCAL_CONF=/etc/M4_DS_PREFIX/local.json
-JSON="/var/www/M4_DS_PREFIX/npm/json -q -f ${LOCAL_CONF}"
+SECURE_LINK_SECRET=${SECURE_LINK_SECRET:-$(LC_ALL=C tr -dc A-Za-z0-9 </dev/urandom | head -c 20)}
 
-SECURE_LINK_SECRET=${SECURE_LINK_SECRET:-$(tr -dc A-Za-z0-9 </dev/urandom | head -c 20)}
+# The secret is interpolated into sed scripts, nginx config and a JS snippet.
+# Restrict it to a safe charset so it cannot break out of any of them.
+case "${SECURE_LINK_SECRET}" in
+	'' | *[!A-Za-z0-9._-]* )
+		echo "documentserver-update-securelink: invalid secret: only [A-Za-z0-9._-] characters are allowed" >&2
+		exit 1
+	;;
+esac
 
-if grep -q secure_link_secret ${NGINX_CONF}; then
-	sed "s,\(set \+\$secure_link_secret\).*,\1 "${SECURE_LINK_SECRET}";," -i ${NGINX_CONF}
-else
-	sed '/server_tokens/a \ \ set $secure_link_secret '"${SECURE_LINK_SECRET}"';' -i ${NGINX_CONF}
-fi
+for conf in "${NGINX_HTTP_CONF}" "${NGINX_SSL_CONF}"; do
+  if [ -f "${conf}" ]; then
+    if grep -q secure_link_secret "${conf}"; then
+      sed -i '' -E 's,(set[[:space:]]+\$secure_link_secret).*,\1 '"${SECURE_LINK_SECRET}"';,' "${conf}"
+    else
+      sed -i '' "/server_tokens/a\\
+\\ \\ set \$secure_link_secret ${SECURE_LINK_SECRET};
+" "${conf}"
+    fi
+  fi
+done
 
-${JSON} -I -e 'if(this.storage===undefined)this.storage={};if(this.storage.fs===undefined)this.storage.fs={};this.storage.fs.secretString="'${SECURE_LINK_SECRET}'"' && chown ds:ds $LOCAL_CONF
+${JSON} -I -e 'if(this.storage===undefined)this.storage={};if(this.storage.fs===undefined)this.storage.fs={};this.storage.fs.secretString="'${SECURE_LINK_SECRET}'"' && chown M4_DS_USER:M4_DS_GROUP $LOCAL_CONF
 
 if [ "$RESTART_CONDITION" != "false" ]; then
-  if pgrep -x ""systemd"" >/dev/null; then
-    systemctl restart ds-docservice
-    systemctl restart ds-converter
-    systemctl reload nginx
-  elif pgrep -x ""supervisord"" >/dev/null; then
+  if pgrep -f "supervisord" >/dev/null; then
     supervisorctl restart ds:docservice
-    supervisorctl restart ds:converter
-    service nginx reload
+    if service nginx onestatus >/dev/null 2>&1; then
+      service nginx onereload
+    fi
   fi
 fi
