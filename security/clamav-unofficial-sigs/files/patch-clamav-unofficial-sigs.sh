--- clamav-unofficial-sigs.sh.orig	2022-03-08 06:43:27 UTC
+++ clamav-unofficial-sigs.sh
@@ -1595,48 +1595,17 @@
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
-    config_files+=( "${config_dir}/master.conf" )
-else
-    xshok_pretty_echo_and_log "ERROR: ${config_dir}/master.conf is not readable"
-    exit 1
-fi
+config_dir="%%PREFIX%%/etc/clamav-unofficial-sigs"
+config_files=("${config_dir}/master.conf")
 if [ -r "${config_dir}/os.conf" ] ; then
     config_files+=( "${config_dir}/os.conf" )
-else
-    #find the a suitable os.*.conf file
-    os_config_number=$(find "$config_dir" -type f -iname "os.*.conf" | wc -l)
-    if [ "$os_config_number" == "0" ] ; then
-        xshok_pretty_echo_and_log "WARNING: no os.conf or os.*.conf found"
-    elif [ "$os_config_number" == "1" ] ; then
-        config_file="$(find "$config_dir" -type f -iname "os.*.conf" | head -n1)"
-        if [ -r "${config_file}" ]; then
-            config_files+=( "${config_file}" )
-        else
-            xshok_pretty_echo_and_log "WARNING: ${config_file} is not readable"
-        fi
-    else
-        xshok_pretty_echo_and_log "WARNING: Too many os.*.conf configs found"
-    fi
 fi
 if [ -r "${config_dir}/user.conf" ] ; then
     config_files+=( "${config_dir}/user.conf" )
-else
-    xshok_pretty_echo_and_log "WARNING: ${config_dir}/user.conf is not readable"
 fi
 
 # Solaris command -v function returns garbage when the program is not found k
@@ -1762,10 +1731,8 @@
         else
             xshok_pretty_echo_and_log "WARNING: ${config_dir}/master.conf not found"
         fi
-        #find the a suitable os.conf or os.*.conf file
-        config_file="$(find "$config_dir" -type f -iname "os.conf" -o -iname "os.*.conf" | tail -n1)"
-        if [ -r "${config_file}" ] ; then
-            config_files+=( "${config_file}" )
+        if [ -r "${config_dir}/os.conf" ] ; then
+            config_files+=( "${config_dir}/os.conf" )
         else
             xshok_pretty_echo_and_log "WARNING: ${config_dir}/os.conf not found"
         fi
