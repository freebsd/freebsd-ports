--- testssl.sh.orig	2020-09-29 09:50:09 UTC
+++ testssl.sh
@@ -132,7 +132,7 @@ declare -r RUN_DIR="$(dirname "$0")"
 declare -r SYSTEM="$(uname -s)"
 declare -r SYSTEMREV="$(uname -r)"
 SYSTEM2=""                                        # currently only being used for WSL = bash on windows
-TESTSSL_INSTALL_DIR="${TESTSSL_INSTALL_DIR:-""}"  # If you run testssl.sh and it doesn't find it necessary file automagically set TESTSSL_INSTALL_DIR
+TESTSSL_INSTALL_DIR="${TESTSSL_INSTALL_DIR:-"%%DATADIR%%"}"  # If you run testssl.sh and it doesn't find it necessary file automagically set TESTSSL_INSTALL_DIR
 CA_BUNDLES_PATH="${CA_BUNDLES_PATH:-""}"          # You can have your stores some place else
 ADDITIONAL_CA_FILES="${ADDITIONAL_CA_FILES:-""}"  # single file with a CA in PEM format or comma separated lists of them
 CIPHERS_BY_STRENGTH_FILE=""
@@ -187,6 +187,9 @@ TERM_CURRPOS=0                                        
 ########### Defining (and presetting) variables which can be changed
 #
 # Following variables make use of $ENV and can be used like "OPENSSL=<myprivate_path_to_openssl> ./testssl.sh <URI>"
+if [[ -z "$OPENSSL" ]]; then
+     OPENSSL=%%PREFIX%%/openssl-unsafe/bin/openssl
+fi
 declare -x OPENSSL
 OPENSSL_TIMEOUT=${OPENSSL_TIMEOUT:-""}  # Default connect timeout with openssl before we call the server side unreachable
 CONNECT_TIMEOUT=${CONNECT_TIMEOUT:-""}  # Default connect timeout with sockets before we call the server side unreachable
@@ -20128,7 +20131,6 @@ lets_roll() {
      mybanner
      check_proxy
      check4openssl_oldfarts
-     check_bsd_mount
 
 
      if "$do_display_only"; then
