--- hb_report/utillib.sh.orig	2017-07-21 09:17:13 UTC
+++ hb_report/utillib.sh
@@ -8,7 +8,7 @@
 get_cluster_type() {
 	if ps -ef | egrep -qs '[a]isexec|[c]orosync' ||
 			[ -f /etc/ais/openais.conf -a ! -f "$HA_CF" ] ||
-			[ -f /etc/corosync/corosync.conf -a ! -f "$HA_CF" ]
+			[ -f %%PREFIX%%/etc/corosync/corosync.conf -a ! -f "$HA_CF" ]
 	then
 		debug "this is OpenAIS cluster stack"
 		echo "openais"
@@ -525,7 +525,7 @@ crmconfig() {
 		CIB_file=$1/$CIB_F crm configure show >$1/$CIB_TXT_F 2>&1
 }
 get_crm_nodes() {
-	/usr/sbin/crm node server
+	%%PREFIX%%/bin/crm node server
 }
 get_live_nodes() {
 	if [ `id -u` = 0 ] && which fping >/dev/null 2>&1; then
