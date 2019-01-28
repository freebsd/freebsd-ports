--- clamav-unofficial-sigs.sh.orig	2018-11-24 16:35:07 UTC
+++ clamav-unofficial-sigs.sh
@@ -1290,7 +1290,7 @@ minimum_required_config_version="72"
 minimum_yara_clamav_version="0.99"
 
 # Default config files
-config_dir="/etc/clamav-unofficial-sigs"
+config_dir="%%PREFIX%%/etc/clamav-unofficial-sigs"
 config_files=( "$config_dir/master.conf" "$config_dir/os.conf" "$config_dir/user.conf" )
 
 # Initialise
@@ -1302,6 +1302,8 @@ force_updates="no"
 enable_log="no"
 custom_config="no"
 we_have_a_config="0"
+pkg_mgr="FreeBSD ports"
+pkg_rm="pkg delete"
 
 # Solaris which function returns garbage when the program is not found
 # only define the new which function if running under Solaris
@@ -1455,7 +1457,7 @@ for config_file in "${config_files[@]}" 
       # Delete both trailing and leading whitespace
       # Delete all trailing whitespace
       # Delete all empty lines
-      clean_config="$(command sed -e '/^#.*/d' -e 's/[[:space:]]#.*//' -e 's/#[[:space:]].*//' -e 's/^[ \t]*//;s/[ \t]*$//' -e '/^\s*$/d' "$config_file")"
+      clean_config="$(command sed -e '/^#.*/d' -e 's/[[:space:]]#.*//' -e 's/#[[:space:]].*//' -e 's/^[[:blank:]]*//;s/[[:blank:]]*$//' -e '/^[[:space:]]*$/d' "$config_file")"
     fi
 
     #fix eval of |
@@ -1470,7 +1472,7 @@ for config_file in "${config_files[@]}" 
     fi
 
     # Check there is an = for every set of "" optional whitespace \s* between = and "
-    config_check_vars="$(echo "$clean_config" | $grep_bin -c '=\s*\"' )"
+    config_check_vars="$(echo "$clean_config" | $grep_bin -c '=[[:space:]]*\"' )"
 
     if [ $(( ${#config_check} / 2 )) -ne "$config_check_vars" ] ; then
       xshok_pretty_echo_and_log "ERROR: Your configuration has errors, every = requires a pair of \"\"" "="
@@ -2131,20 +2133,11 @@ if [ "$sanesecurity_enabled" == "yes" ] 
         xshok_pretty_echo_and_log "Sanesecurity Database & GPG Signature File Updates" "="
         xshok_pretty_echo_and_log "Checking for Sanesecurity updates..."
 
-        sanesecurity_mirror_ips="$(dig +ignore +short "$sanesecurity_url")"
-        # Add fallback to host if dig returns no records
-        if [ ${#sanesecurity_mirror_ips} -lt 1 ] ; then
-          sanesecurity_mirror_ips="$(host -t A "$sanesecurity_url" | sed -n '/has address/{s/.*address \([^ ]*\).*/\1/;p;}')"
-        fi
+        sanesecurity_mirror_ips=$(host "$sanesecurity_url" | sed 's/.*[[:space:]]//')
 
         if [ ${#sanesecurity_mirror_ips} -ge 1 ] ; then
           for sanesecurity_mirror_ip in $sanesecurity_mirror_ips ; do
-            sanesecurity_mirror_name=""
-            sanesecurity_mirror_name="$(dig +short -x "$sanesecurity_mirror_ip" | command sed 's/\.$//')"
-            # Add fallback to host if dig returns no records
-            if [ -z "$sanesecurity_mirror_name" ] ; then
-              sanesecurity_mirror_name="$(host "$sanesecurity_mirror_ip" | sed -n '/name pointer/{s/.*pointer \([^ ]*\).*\.$/\1/;p;}')"
-            fi
+            sanesecurity_mirror_name=$(host "$sanesecurity_mirror_ip" | sed 's/.*[[:space:]]//' | sed 's/\.$//')
             sanesecurity_mirror_site_info="$sanesecurity_mirror_name $sanesecurity_mirror_ip"
             xshok_pretty_echo_and_log "Sanesecurity mirror site used: $sanesecurity_mirror_site_info"
             # shellcheck disable=SC2086
