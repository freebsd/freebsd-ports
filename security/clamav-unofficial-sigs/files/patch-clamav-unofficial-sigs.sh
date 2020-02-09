--- clamav-unofficial-sigs.sh.orig	2020-02-08 22:48:12 UTC
+++ clamav-unofficial-sigs.sh
@@ -1541,48 +1541,17 @@ force_wget="no"
 enable_log="no"
 custom_config="no"
 we_have_a_config="0"
+pkg_mgr="FreeBSD ports"
+pkg_rm="pkg delete"
 
-
-# Attempt to scan for a valid config dir
-if [ -f "/etc/clamav-unofficial-sigs/master.conf" ] ; then
-  config_dir="/etc/clamav-unofficial-sigs"
-elif [ -f "/usr/local/etc/clamav-unofficial-sigs/master.conf" ] ; then
-  config_dir="/usr/local/etc/clamav-unofficial-sigs/"
-elif [ -f "/opt/zimbra/conf/clamav-unofficial-sigs/master.conf" ] ; then
-  config_dir="/opt/zimbra/conf/clamav-unofficial-sigs/"
-else
-  xshok_pretty_echo_and_log "ERROR: config_dir (/etc/clamav-unofficial-sigs/master.conf) could not be found"
-  exit 1
-fi
 # Default config files
-if [ -r "${config_dir}/master.conf" ] ; then
-	config_files+=( "${config_dir}/master.conf" )
-else
-	xshok_pretty_echo_and_log "ERROR: ${config_dir}/master.conf is not readable"
-	exit 1
-fi
+config_dir="%%PREFIX%%/etc/clamav-unofficial-sigs"
+config_files=("${config_dir}/master.conf")
 if [ -r "${config_dir}/os.conf" ] ; then
 	config_files+=( "${config_dir}/os.conf" )
-else
-	#find the a suitable os.*.conf file
-	os_config_number=$(find "$config_dir" -type f -iname "os.*.conf" | wc -l)
-	if [ "$os_config_number" == "0" ] ; then
-		xshok_pretty_echo_and_log "WARNING: no os.conf or os.*.conf found"
-	elif [ "$os_config_number" == "1" ] ; then
-		config_file="$(find "$config_dir" -type f -iname "os.*.conf" | head -n1)"
-		if [ -r "${config_file}" ]; then
-			config_files+=( "${config_file}" )
-		else
-			xshok_pretty_echo_and_log "WARNING: ${config_file} is not readable"
-		fi
-	else
-		xshok_pretty_echo_and_log "WARNING: Too many os.*.conf configs found"
-	fi
 fi
 if [ -r "${config_dir}/user.conf" ] ; then
 	config_files+=( "${config_dir}/user.conf" )
-else
-	xshok_pretty_echo_and_log "WARNING: ${config_dir}/user.conf is not readable"
 fi
 
 # Solaris command -v function returns garbage when the program is not found
@@ -1718,10 +1687,8 @@ if [ "$custom_config" != "no" ] ; then
 		else
 			xshok_pretty_echo_and_log "WARNING: ${config_dir}/master.conf not found"
 		fi
-		#find the a suitable os.conf or os.*.conf file
-		config_file="$(find "$config_dir" -type f -iname "os.conf" -o -iname "os.*.conf" | tail -n1)"
-		if [ -r "${config_file}" ] ; then
-			config_files+=( "${config_file}" )
+		if [ -r "${config_dir}/os.conf" ] ; then
+			config_files+=( "${config_dir}/os.conf" )
 		else
 			xshok_pretty_echo_and_log "WARNING: ${config_dir}/os.conf not found"
 		fi
@@ -1767,7 +1734,7 @@ for config_file in "${config_files[@]}" ; do
       # Delete both trailing and leading whitespace
       # Delete all trailing whitespace
       # Delete all empty lines
-      clean_config="$(command sed -e '/^#.*/d' -e 's/[[:space:]]#.*//' -e 's/#[[:space:]].*//' -e 's/^[ \t]*//;s/[ \t]*$//' -e '/^\s*$/d' "$config_file")"
+      clean_config="$(command sed -e '/^#.*/d' -e 's/[[:space:]]#.*//' -e 's/#[[:space:]].*//' -e 's/^[[:blank:]]*//;s/[[:blank:]]*$//' -e '/^[[:space:]]*$/d' "$config_file")"
     fi
 
     #fix eval of |
@@ -1782,7 +1749,7 @@ for config_file in "${config_files[@]}" ; do
     fi
 
     # Check there is an = for every set of "" optional whitespace \s* between = and "
-    config_check_vars="$(echo "$clean_config" | $grep_bin -c '=\s*\"' )"
+    config_check_vars="$(echo "$clean_config" | $grep_bin -c '=[[:space:]]*\"' )"
 
     if [ $(( ${#config_check} / 2 )) -ne "$config_check_vars" ] ; then
       xshok_pretty_echo_and_log "ERROR: Your configuration has errors, every = requires a pair of \"\""
@@ -2504,24 +2471,12 @@ if [ "$sanesecurity_enabled" == "yes" ] ; then
         echo "$current_time" > "${work_dir_work_configs}/last-ss-update.txt"
         xshok_pretty_echo_and_log "Sanesecurity Database & GPG Signature File Updates" "="
         xshok_pretty_echo_and_log "Checking for Sanesecurity updates..."
-				# shellcheck disable=SC2086
-        sanesecurity_mirror_ips="$(dig $dig_proxy +ignore +short "$sanesecurity_url")"
-        # Add fallback to host if dig returns no records
-        if [ ${#sanesecurity_mirror_ips} -lt 1 ] ; then
-					# shellcheck disable=SC2086
-          sanesecurity_mirror_ips="$(host $host_proxy -t A "$sanesecurity_url" | sed -n '/has address/{s/.*address \([^ ]*\).*/\1/;p;}')"
-        fi
 
+        sanesecurity_mirror_ips=$(host "$sanesecurity_url" | sed 's/.*[[:space:]]//')
+
         if [ ${#sanesecurity_mirror_ips} -ge 1 ] ; then
           for sanesecurity_mirror_ip in $sanesecurity_mirror_ips ; do
-            sanesecurity_mirror_name=""
-						# shellcheck disable=SC2086
-            sanesecurity_mirror_name="$(dig $dig_proxy +short -x "$sanesecurity_mirror_ip" | command sed 's/\.$//')"
-            # Add fallback to host if dig returns no records
-            if [ -z "$sanesecurity_mirror_name" ] ; then
-							# shellcheck disable=SC2086
-              sanesecurity_mirror_name="$(host $host_proxy "$sanesecurity_mirror_ip" | sed -n '/name pointer/{s/.*pointer \([^ ]*\).*\.$/\1/;p;}')"
-            fi
+            sanesecurity_mirror_name=$(host "$sanesecurity_mirror_ip" | sed 's/.*[[:space:]]//' | sed 's/\.$//')
             sanesecurity_mirror_site_info="$sanesecurity_mirror_name $sanesecurity_mirror_ip"
             xshok_pretty_echo_and_log "Sanesecurity mirror site used: ${sanesecurity_mirror_site_info}"
             # shellcheck disable=SC2086
@@ -2834,7 +2789,7 @@ if [ "$linuxmalwaredetect_enabled" == "yes" ] ; then
           ret="$?"
           if [ "$ret" -eq 0 ] ; then
 						# shellcheck disable=SC2035
-            $tar_bin --strip-components=1 --wildcards --overwrite -xzf "${work_dir_linuxmalwaredetect}/sigpack.tgz" --directory "${work_dir_linuxmalwaredetect}" */rfxn.*
+            $tar_bin --strip-components=1 -xzf "${work_dir_linuxmalwaredetect}/sigpack.tgz" --directory "${work_dir_linuxmalwaredetect}" "*/rfxn.*"
             for db_file in "${linuxmalwaredetect_dbs[@]}" ; do
               if [ "$loop" == "1" ] ; then
                 xshok_pretty_echo_and_log "---"
