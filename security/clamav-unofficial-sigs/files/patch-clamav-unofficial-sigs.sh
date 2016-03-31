--- clamav-unofficial-sigs.sh.orig	2016-03-31 14:38:13 UTC
+++ clamav-unofficial-sigs.sh
@@ -158,7 +158,7 @@ minimum_required_config_version="56"
 version_date="31 March 2016"
 
 #default config files
-config_dir="/etc/clamav-unofficial-sigs"
+config_dir="%%PREFIX%%/etc/clamav-unofficial-sigs"
 config_files=("$config_dir/master.conf" "$config_dir/os.conf" "$config_dir/user.conf")
 
 
@@ -542,6 +542,8 @@ make_signature_database_from_ascii_file 
 #Remove the clamav-unofficial-sigs script
 remove_script () {
 	echo ""
+	pkg_mgr="FreeBSD ports"
+	pkg_rm="pkg delete"
 	if [ -n "$pkg_mgr" -a -n "$pkg_rm" ] ; then
 		echo "  This script (clamav-unofficial-sigs) was installed on the system"
 		echo "  via '$pkg_mgr', use '$pkg_rm' to remove the script"
@@ -1088,9 +1090,9 @@ if [ "$sanesecurity_enabled" == "yes" ] 
 		db_file=""
 
 		xshok_pretty_echo_and_log "Sanesecurity Database & GPG Signature File Updates" "="
-		sanesecurity_mirror_ips=`dig +ignore +short $sanesecurity_url`
+		sanesecurity_mirror_ips=`host $sanesecurity_url | sed 's/.*\s//'`
 		for sanesecurity_mirror_ip in $sanesecurity_mirror_ips ; do
-			sanesecurity_mirror_name=`dig +short -x $sanesecurity_mirror_ip | command sed 's/\.$//'`
+			sanesecurity_mirror_name=`host $sanesecurity_mirror_ip | sed 's/.*\s//' | sed 's/\.$//'`
 			sanesecurity_mirror_site_info="$sanesecurity_mirror_name $sanesecurity_mirror_ip"
 			xshok_pretty_echo_and_log "Sanesecurity mirror site used: $sanesecurity_mirror_site_info"
 			rsync $rsync_output_level $no_motd --files-from=$sanesecurity_include_dbs -ctuz $connect_timeout --timeout="$rsync_max_time" --stats rsync://$sanesecurity_mirror_ip/sanesecurity $sanesecurity_dir 2>/dev/null
