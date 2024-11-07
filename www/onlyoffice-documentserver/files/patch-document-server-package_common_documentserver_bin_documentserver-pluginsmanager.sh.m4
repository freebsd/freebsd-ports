--- document-server-package/common/documentserver/bin/documentserver-pluginsmanager.sh.m4.orig	2023-06-20 13:51:11 UTC
+++ document-server-package/common/documentserver/bin/documentserver-pluginsmanager.sh.m4
@@ -1,35 +1,33 @@
-#!/bin/bash
+#!/bin/sh
 
-[ $(id -u) -ne 0 ] && { echo "Root privileges required"; exit 1; }
+[ "$(id -u)" -ne 0 ] && { echo "Root privileges required"; exit 1; }
 
-while [ "$1" != "" ]; do
+while [ $# -gt 0 ]; do
 	case $1 in
-
 		-r | --restart )
-			if [ "$2" != "" ]; then
+			if [ "$2" = "true" ] || [ "$2" = "false" ]; then
 				RESTART_CONDITION=$2
 				shift
 			fi
+			shift
 		;;
-		
-		* ) args+=("$1");
+		*)
+			break
+		;;
 	esac
-	shift
 done
 
-export LD_LIBRARY_PATH=/var/www/M4_DS_PREFIX/server/FileConverter/bin:$LD_LIBRARY_PATH
+export LD_LIBRARY_PATH=%%LOCALBASE%%/www/M4_DS_PREFIX/server/FileConverter/bin:$LD_LIBRARY_PATH
 
-PLUGIN_MANAGER="/var/www/M4_DS_PREFIX/server/tools/pluginsmanager"
-PLUGIN_DIR="/var/www/M4_DS_PREFIX/sdkjs-plugins/"
+PLUGIN_MANAGER="%%LOCALBASE%%/www/M4_DS_PREFIX/server/tools/pluginsmanager"
+PLUGIN_DIR="%%LOCALBASE%%/www/M4_DS_PREFIX/sdkjs-plugins/"
 
-"${PLUGIN_MANAGER}" --directory=\"${PLUGIN_DIR}\" "${args[@]}"
+"${PLUGIN_MANAGER}" --directory=\"${PLUGIN_DIR}\" "$@"
 
-chown -R ds:ds "${PLUGIN_DIR}"
+chown -R onlyoffice:onlyoffice "${PLUGIN_DIR}"
 
 if [ "$RESTART_CONDITION" != "false" ]; then
-	if pgrep -x ""systemd"" >/dev/null; then
-		systemctl restart ds-docservice
-	elif pgrep -x ""supervisord"" >/dev/null; then
+	if pgrep -f "supervisord" >/dev/null; then
 		supervisorctl restart ds:docservice
 	fi
 	documentserver-flush-cache.sh
