--- protonvpn-cli.sh.orig	2018-11-05 20:42:22 UTC
+++ protonvpn-cli.sh
@@ -17,63 +17,6 @@ if [[ ("$UID" != 0) && ("$1" != "ip") && ("$1" != "-ip
   exit 1
 fi
 
-function check_requirements() {
-  if [[ -z $(which openvpn) ]]; then
-    echo "[!] Error: openvpn is not installed. Install \`openvpn\` package to continue."
-    exit 1
-  fi
-
-  if [[ ! -z $(which python) ]]; then
-    python=$(which python)
-  elif [[ ! -z $(which python3) ]]; then
-    python=$(which python3)
-  elif [[ ! -z $(which python2) ]]; then
-    python=$(which python2)
-  fi
-
-  if [[ -z "$python" ]]; then
-    echo "[!] Error: python is not installed. Install \`python\` package to continue."
-    exit 1
-  fi
-
-  if [[ -z $(which dialog) ]]; then
-    echo "[!] Error: dialog is not installed. Install \`dialog\` package to continue."
-    exit 1
-  fi
-  if [[ -z $(which wget) ]]; then
-    echo "[!] Error: wget is not installed. Install \`wget\` package to continue."
-    exit 1
-  fi
-
-  if [[ -z $(which sysctl) && ( $(detect_platform_type) != "Mac" ) ]]; then
-    echo "[!] Error: sysctl is not installed. Install \`sysctl\` package to continue."
-    exit 1
-  fi
-
-  if [[ $(detect_platform_type) == "Linux" ]]; then
-    if [[ ( -z $(which iptables) ) ||  ( -z $(which iptables-save) ) || ( -z $(which iptables-restore) ) ]]; then
-      echo "[!] Error: iptables is not installed. Install \`iptables\` package to continue."
-      exit 1
-    fi
-  fi
-
-  sha512sum_func
-  if [[ -z "$sha512sum_tool" ]]; then
-    echo "[!] Error: sha512sum is not installed. Install \`sha512sum\` package to continue."
-    exit 1
-  fi
-
-  if [[ (! -x "/etc/openvpn/update-resolv-conf") && ( $(detect_platform_type) != "MacOS") ]]; then
-    echo "[!] Error: update-resolv-conf is not installed."
-    read -p "Would you like protonvpn-cli to install update-resolv-conf? (y/N): " "user_confirm"
-    if [[ "$user_confirm" == "y" || "$user_confirm" == "Y" ]]; then
-      install_update_resolv_conf
-    else
-      exit 1
-    fi
-  fi
-}
-
 function get_home() {
   if [[ -z "$SUDO_USER" ]]; then
     CURRENT_USER="$(whoami)"
@@ -100,25 +43,6 @@ function get_protonvpn_cli_home() {
   echo "$(get_home)/.protonvpn-cli"
 }
 
-function install_update_resolv_conf() {
-  if [[ ("$UID" != 0) ]]; then
-    echo "[!] Error: Installation requires root access."
-    exit 1
-  fi
-  echo "[*] Installing update-resolv-conf..."
-  mkdir -p "/etc/openvpn/"
-  file_sha512sum="81cf5ed20ec2a2f47f970bb0185fffb3e719181240f2ca3187dbee1f4d102ce63ab048ffee9daa6b68c96ac59d1d86ad4de2b1cfaf77f1b1f1918d143e96a588"
-  wget "https://raw.githubusercontent.com/ProtonVPN/scripts/master/update-resolv-conf.sh" -O "/etc/openvpn/update-resolv-conf"
-  if [[ ($? == 0) && ($($sha512sum_tool "/etc/openvpn/update-resolv-conf" | cut -d " " -f1) == "$file_sha512sum")  ]]; then
-    chmod +x "/etc/openvpn/update-resolv-conf"
-    echo "[*] Done."
-  else
-    echo "[!] Error installing update-resolv-conf."
-    rm -f "/etc/openvpn/update-resolv-conf" 2> /dev/null
-    exit 1
-  fi
-}
-
 function check_ip() {
   counter=0
   ip=""
@@ -222,15 +146,7 @@ function init_cli() {
 }
 
 function detect_platform_type() {
-  unameOut="$(uname -s)"
-  case "${unameOut}" in
-    Linux*)     platform=Linux;;
-    Darwin*)    platform=MacOS;;
-    CYGWIN*)    platform=Linux;;
-    MINGW*)     platform=Linux;;
-    *)          platform=Linux
-  esac
-  echo "$platform"
+  echo "FreeBSD"
 }
 
 function manage_ipv6() {
@@ -501,7 +417,8 @@ function openvpn_connect() {
     --header 'Accept: application/vnd.protonmail.v1+json' \
     -o /dev/null \
     --timeout 10 --tries 1 -q -O "$openvpn_config" \
-    "https://api.protonmail.ch/vpn/config?Platform=$(detect_platform_type)&LogicalID=$config_id&Protocol=$selected_protocol"
+    "https://api.protonmail.ch/vpn/config?Platform=Linux&LogicalID=$config_id&Protocol=$selected_protocol" && \
+  sed -i '' s,/etc/openvpn/update-resolv-conf,%%LOCALBASE%%/etc/openvpn/update-resolv-conf, "$openvpn_config"
 
   echo "Connecting..."
 
@@ -573,102 +490,6 @@ function openvpn_connect() {
   exit $status_exit
 }
 
-function update_cli() {
-  check_if_internet_is_working_normally
-
-  cli_path="/usr/local/bin/protonvpn-cli"
-  if [[ ! -f "$cli_path" ]]; then
-    echo "[!] Error: protonvpn-cli does not seem to be installed."
-    exit 1
-  fi
-  echo "[#] Checking for update..."
-  current_local_hashsum=$($sha512sum_tool "$cli_path" | cut -d " " -f1)
-  remote_=$(wget --timeout 6 -o /dev/null -q -O - 'https://raw.githubusercontent.com/ProtonVPN/protonvpn-cli/master/protonvpn-cli.sh')
-  if [[ $? != 0 ]]; then
-    echo "[!] Error: There is an error updating protonvpn-cli."
-    exit 1
-  fi
-  remote_hashsum=$(echo "$remote_" | $sha512sum_tool | cut -d ' ' -f1)
-
-  if [[ "$current_local_hashsum" == "$remote_hashsum" ]]; then
-    echo "[*] protonvpn-cli is up-to-date!"
-    exit 0
-  else
-    echo "[#] A new update is available."
-    echo "[#] Updating..."
-    wget -q --timeout 20 -O "$cli_path" 'https://raw.githubusercontent.com/ProtonVPN/protonvpn-cli/master/protonvpn-cli.sh'
-    if [[ $? == 0 ]]; then
-      echo "[#] protonvpn-cli has been updated successfully."
-      exit 0
-    else
-      echo "[!] Error: There is an error updating protonvpn-cli."
-      exit 1
-    fi
-  fi
-}
-
-function install_cli() {
-  mkdir -p "/usr/bin/" "/usr/local/bin/"
-  cli="$(cd "$(dirname "$0")" && pwd -P)/$(basename "$0")"
-  errors_counter=0
-  cp "$cli" "/usr/local/bin/protonvpn-cli" &> /dev/null
-  if [[ $? != 0 ]]; then errors_counter=$((errors_counter+1)); fi
-
-  ln -s -f "/usr/local/bin/protonvpn-cli" "/usr/local/bin/pvpn" &> /dev/null
-  if [[ $? != 0 ]]; then errors_counter=$((errors_counter+1)); fi
-
-  ln -s -f "/usr/local/bin/protonvpn-cli" "/usr/bin/protonvpn-cli" &> /dev/null
-  if [[ $? != 0 ]]; then errors_counter=$((errors_counter+1)); fi
-
-  ln -s -f "/usr/local/bin/protonvpn-cli" "/usr/bin/pvpn" &> /dev/null
-  if [[ $? != 0 ]]; then errors_counter=$((errors_counter+1)); fi
-
-  chown "$USER:$(id -gn $USER)" "/usr/local/bin/protonvpn-cli" "/usr/local/bin/pvpn" "/usr/bin/protonvpn-cli" "/usr/bin/pvpn" &> /dev/null
-  if [[ $? != 0 ]]; then errors_counter=$((errors_counter+1)); fi
-
-  chmod 0755 "/usr/local/bin/protonvpn-cli" "/usr/local/bin/pvpn" "/usr/bin/protonvpn-cli" "/usr/bin/pvpn" &> /dev/null
-  if [[ $? != 0 ]]; then errors_counter=$((errors_counter+1)); fi
-
-  if [[ ($errors_counter == 0) || ( ! -z $(which protonvpn-cli) ) ]]; then
-    echo "[*] Done."
-    exit 0
-  else
-    echo "[!] Error: There was an error in installing protonvpn-cli."
-    exit 1
-  fi
-}
-
-function uninstall_cli() {
-
-  if [[ $(is_openvpn_currently_running) == true ]]; then
-    echo "[!] OpenVPN is currently running."
-    echo "[!] Session will be disconnected."
-    openvpn_disconnect quiet dont_exit
-    if [[ $(is_openvpn_currently_running) == true ]]; then  # Checking if OpenVPN is still active.
-      echo "[!] Error disconnecting OpenVPN."
-      echo "[!] Please disconnect manually and try the uninstallation again."
-      exit 1
-    else
-      echo "[#] Disconnected."
-    fi
-  fi
-
-  errors_counter=0
-  rm -f "/usr/local/bin/protonvpn-cli" "/usr/local/bin/pvpn" "/usr/bin/protonvpn-cli" "/usr/bin/pvpn" &> /dev/null
-  if [[ $? != 0 ]]; then errors_counter=$((errors_counter+1)); fi
-
-  rm -rf "$(get_protonvpn_cli_home)/" &> /dev/null
-  if [[ $? != 0 ]]; then errors_counter=$((errors_counter+1)); fi
-
-  if [[ ($errors_counter == 0) || ( $(which protonvpn-cli) == "" ) ]]; then
-    echo "[*] Done."
-    exit 0
-  else
-    echo "[!] Error: There was an error in uninstalling protonvpn-cli."
-    exit 1
-  fi
-}
-
 function print_console_status() {
   current_ip="$(check_ip)"
   if [[ $(is_openvpn_currently_running) == true ]]; then
@@ -1246,6 +1067,18 @@ function get_countries_server_list() {
   response_cache_path="$(get_protonvpn_cli_home)/.response_cache"
   tier=$(cat "$(get_protonvpn_cli_home)/protonvpn_tier")
 
+  country_id=$1
+  if [[ $tier -eq 0 ]]
+  then
+    if [[ $1 -eq 1 ]]
+    then
+      country_id=9
+    elif [[ $1 -eq 2 ]]
+    then
+      country_id=6
+    fi
+  fi
+
   output=`$python <<END
 import json
 response_cache = open("""$response_cache_path""", "r").read()
@@ -1263,7 +1096,7 @@ for _ in output:
     countries.append(_['EntryCountry'])
 
 for i, country in enumerate(countries):
-	if str(i+1) == """$1""":
+	if str(i+1) == """$country_id""":
 		selected_country = country
 
 best_server = ""
@@ -1536,9 +1369,6 @@ function help_message() {
     echo "   --reconnect                         Reconnect to the current ProtonVPN server."
     echo "   --ip                                Print the current public IP address."
     echo "   --status                            Print connection status."
-    echo "   --update                            Update protonvpn-cli."
-    echo "   --install                           Install protonvpn-cli."
-    echo "   --uninstall                         Uninstall protonvpn-cli."
     echo "   -v, --version                       Display version."
     echo "   -h, --help                          Show this help message."
     echo
@@ -1546,7 +1376,6 @@ function help_message() {
     exit 0
 }
 
-check_requirements
 user_input="$1"
 case $user_input in
   ""|"-h"|"--help"|"--h"|"-help"|"help") help_message
@@ -1589,13 +1418,7 @@ case $user_input in
     ;;
     "status"|"-status"|"--status") print_console_status
     ;;
-  "update"|"-update"|"--update") update_cli
-    ;;
   "-init"|"--init") init_cli
-    ;;
-  "-install"|"--install") install_cli
-    ;;
-  "-uninstall"|"--uninstall") uninstall_cli
     ;;
   *)
   echo "[!] Invalid input: $user_input"
