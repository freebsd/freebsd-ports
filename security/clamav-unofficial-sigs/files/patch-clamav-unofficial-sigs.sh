--- clamav-unofficial-sigs.sh.orig	2016-11-18 10:05:40 UTC
+++ clamav-unofficial-sigs.sh
@@ -753,6 +753,8 @@ function make_signature_database_from_as
 #Remove the clamav-unofficial-sigs script
 function remove_script () {
   echo ""
+  pkg_mgr="FreeBSD ports"
+  pkg_rm="pkg delete"
   if [ -n "$pkg_mgr" ] && [ -n "$pkg_rm" ] ; then
     echo "This script (clamav-unofficial-sigs) was installed on the system via '$pkg_mgr'"
     echo "use '$pkg_rm' to remove the script and all of its associated files and databases from the system."
@@ -1151,7 +1153,7 @@ minimum_required_config_version="65"
 minimum_yara_clamav_version="0.99"
 
 #default config files
-config_dir="/etc/clamav-unofficial-sigs"
+config_dir="%%PREFIX%%/etc/clamav-unofficial-sigs"
 config_files=("$config_dir/master.conf" "$config_dir/os.conf" "$config_dir/user.conf")
 
 #Initialise 
@@ -1879,20 +1881,11 @@ if [ "$sanesecurity_enabled" == "yes" ] 
         xshok_pretty_echo_and_log "Sanesecurity Database & GPG Signature File Updates" "="
         xshok_pretty_echo_and_log "Checking for Sanesecurity updates..."
 
-        sanesecurity_mirror_ips=$(dig +ignore +short "$sanesecurity_url")
-        #add fallback to host if dig returns no records
-        if [ "$(xshok_array_count  "$sanesecurity_mirror_ips")" -lt 1 ] ; then
-          sanesecurity_mirror_ips=$(host -t A "$sanesecurity_url" | sed -n '/has address/{s/.*address \([^ ]*\).*/\1/;p;}')
-        fi
+        sanesecurity_mirror_ips=$(host "$sanesecurity_url" | sed 's/.*[[:space:]]//')
 
         if [ "$(xshok_array_count  "$sanesecurity_mirror_ips")" -ge "1" ] ; then
           for sanesecurity_mirror_ip in $sanesecurity_mirror_ips ; do
-            sanesecurity_mirror_name=""
-            sanesecurity_mirror_name=$(dig +short -x "$sanesecurity_mirror_ip" | command sed 's/\.$//')
-            #add fallback to host if dig returns no records
-            if [ "$sanesecurity_mirror_name" == "" ] ; then
-              sanesecurity_mirror_name=$(host "$sanesecurity_mirror_ip" | sed -n '/name pointer/{s/.*pointer \([^ ]*\).*\.$/\1/;p;}')
-            fi
+            sanesecurity_mirror_name=$(host "$sanesecurity_mirror_ip" | sed 's/.*[[:space:]]//' | sed 's/\.$//')
             sanesecurity_mirror_site_info="$sanesecurity_mirror_name $sanesecurity_mirror_ip"
             xshok_pretty_echo_and_log "Sanesecurity mirror site used: $sanesecurity_mirror_site_info"
             $rsync_bin $rsync_output_level $no_motd --files-from="$sanesecurity_include_dbs" -ctuz $connect_timeout --timeout="$rsync_max_time" "rsync://$sanesecurity_mirror_ip/sanesecurity" "$work_dir_sanesecurity" 2>/dev/null
