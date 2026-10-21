--- document-server-package/common/documentserver/bin/documentserver-jwt-status.m4.orig        2026-10-11 09:45:15 UTC
+++ document-server-package/common/documentserver/bin/documentserver-jwt-status.m4
@@ -1,27 +1,27 @@
-#!/bin/bash
+#!/bin/sh
 
-[ $(id -u) -ne 0 ] && { echo "Root privileges required"; exit 1; }
+[ "$(id -u)" -ne 0 ] && { echo "Root privileges required"; exit 1; }
 
-CONF_DIR="/etc/M4_DS_PREFIX"
-DIR="/var/www/M4_DS_PREFIX"
+CONF_DIR="M4_DS_CONF"
+DIR="M4_DS_ROOT"
 
 LOCAL_CONFIG="${CONF_DIR}/local.json"
 DEFAULT_CONFIG="${CONF_DIR}/default.json"
-Configs=("$LOCAL_CONFIG" "$DEFAULT_CONFIG")
+Configs="$LOCAL_CONFIG $DEFAULT_CONFIG"
 
 JSON_BIN="$DIR/npm/json"
 
-for i in "${!Configs[@]}";
+for i in ${Configs};
 do
-	if [ -f ${Configs[$i]} ]; then
-		JSON="$JSON_BIN -f ${Configs[$i]}"
+	if [ -f "${i}" ]; then
+		JSON="$JSON_BIN -f ${i}"
 		JWT_ENABLED=$($JSON "services.CoAuthoring.token.enable.request.inbox")	
 		JWT_SECRET=$($JSON "services.CoAuthoring.secret.inbox.string")
 		JWT_HEADER=$($JSON "services.CoAuthoring.token.inbox.header")
 		if [ -n "$JWT_ENABLED" ]; then	
 			echo "Your JWT settings:"
 			echo "JWT enabled -  $JWT_ENABLED"
-			if [ $JWT_ENABLED = "true" ]; then
+			if [ "${JWT_ENABLED}" = "true" ]; then
 				echo "JWT secret  -  $JWT_SECRET"
 				echo "JWT header  -  $JWT_HEADER"		
 			fi
