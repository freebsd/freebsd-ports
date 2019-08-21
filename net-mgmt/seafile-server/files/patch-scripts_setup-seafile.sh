--- scripts/setup-seafile.sh.orig	2019-08-20 19:25:53 UTC
+++ scripts/setup-seafile.sh
@@ -17,6 +17,8 @@ use_existing_seafile="false"
 
 server_manual_http="https://github.com/haiwen/seafile/wiki"
 
+os_bsd=$(uname | grep -cm1 -e BSD -e DragonFly)
+
 function welcome () {
     echo "-----------------------------------------------------------------"
     echo "This script will guide you to config and setup your seafile server."
@@ -343,10 +345,17 @@ fi
 }
 
 function copy_user_manuals() {
-    src_docs_dir=${INSTALLPATH}/seafile/docs/
+    if [ $os_bsd == "1" ]; then
+        src_docs_dir=${INSTALLPATH}/seafile/share/doc/seafile/
+    else
+    	src_docs_dir=${INSTALLPATH}/seafile/docs/
+    fi
     library_template_dir=${seafile_data_dir}/library-template
     mkdir -p ${library_template_dir}
     cp -f ${src_docs_dir}/*.doc ${library_template_dir}
+    if [ $os_bsd == "1" ]; then
+    	chown -R %%SEAFILE_USER%%:%%SEAFILE_GROUP%% "${library_template_dir}"
+    fi
 }
 
 function parse_params() {
@@ -662,7 +671,12 @@ function get_seahub_admin_passwd () {
 echo "Creating database now, it may take one minute, please wait... "
 echo
 
-cd ${TOPDIR}/ccnet && mkdir -m 0755 GroupMgr misc OrgMgr PeerMgr && cd -
+if [ $os_bsd == "1" ]; then
+    cd ${TOPDIR}/ccnet && install -d -m 0755 -o %%SEAFILE_USER%% -g %%SEAFILE_GROUP%% \
+    GroupMgr misc OrgMgr PeerMgr && cd -
+else
+    cd ${TOPDIR}/ccnet && mkdir -m 0755 GroupMgr misc OrgMgr PeerMgr && cd -
+fi
 
 ccnet_group_db=${TOPDIR}/ccnet/GroupMgr/groupmgr.db
 ccnet_group_sql=${INSTALLPATH}/sql/sqlite/groupmgr.sql
@@ -740,6 +754,14 @@ chmod 0600 "$dest_settings_py"
 chmod 0700 "$default_ccnet_conf_dir"
 chmod 0700 "$seafile_data_dir"
 chmod 0700 "$default_conf_dir"
+if [ $os_bsd == "1" ]; then
+	for file in "$dest_settings_py" "$default_ccnet_conf_dir" \
+	"$default_conf_dir" "$seahub_db" "$ccnet_group_db" "$ccnet_config_db" \
+	"$ccnet_org_db" "$ccnet_user_db"; do
+		chown %%SEAFILE_USER%%:%%SEAFILE_GROUP%% "$file"
+	done
+	chown -R %%SEAFILE_USER%%:%%SEAFILE_GROUP%% "$seafile_data_dir"
+fi
 
 # -------------------------------------------
 # copy user manuals to library template
@@ -756,9 +778,17 @@ echo
 echo "-----------------------------------------------------------------"
 echo "Your seafile server configuration has been completed successfully." 
 echo "-----------------------------------------------------------------"
-echo 
-echo "run seafile server:     ./seafile.sh { start | stop | restart }"
-echo "run seahub  server:     ./seahub.sh  { start <port> | stop | restart <port> }"
+echo
+if [ $os_bsd == "1" ]; then
+	echo "run seafile server:     sysrc seafile_enable=YES"
+	echo "                        service seafile { start | stop | restart }"
+	echo "run seahub  server:     sysrc seahub_enable=YES"
+	echo "                        service seahub { start | stop | restart }"
+	echo "run reset-admin:        ./reset-admin.sh"
+else
+	echo "run seafile server:     ./seafile.sh { start | stop | restart }"
+	echo "run seahub  server:     ./seahub.sh  { start <port> | stop | restart <port> }"
+fi
 echo
 echo "-----------------------------------------------------------------"
 echo "If the server is behind a firewall, remember to open these tcp ports:"
