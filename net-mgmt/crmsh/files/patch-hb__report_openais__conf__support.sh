--- hb_report/openais_conf_support.sh.orig	2018-04-19 04:02:39 UTC
+++ hb_report/openais_conf_support.sh
@@ -70,8 +70,8 @@ getlogvars() {
 }
 cluster_info() {
 	: echo "openais version: how?"
-	if [ "$CONF" = /etc/corosync/corosync.conf ]; then
-		/usr/sbin/corosync -v
+	if [ "$CONF" = %%PREFIX%%/etc/corosync/corosync.conf ]; then
+		%%PREFIX%%/sbin/corosync -v
 	fi
 }
 essential_files() {
