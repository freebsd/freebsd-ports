--- testssl.sh.orig	2025-04-23 10:29:50 UTC
+++ testssl.sh
@@ -193,7 +193,7 @@ ADDTL_CA_FILES="${ADDTL_CA_FILES:-""}"  # single file 
 
 ########### Tuning vars which cannot be set by a cmd line switch. Use instead e.g "HEADER_MAXSLEEP=10 ./testssl.sh <your_args_here>"
 #
-TESTSSL_INSTALL_DIR="${TESTSSL_INSTALL_DIR:-""}"  # If you run testssl.sh and it doesn't find it necessary file automagically set TESTSSL_INSTALL_DIR
+TESTSSL_INSTALL_DIR="${TESTSSL_INSTALL_DIR:-"%%DATADIR%%"}"  # If you run testssl.sh and it doesn't find it necessary file automagically set TESTSSL_INSTALL_DIR
 CA_BUNDLES_PATH="${CA_BUNDLES_PATH:-""}"          # You can have your CA stores some place else
 EXPERIMENTAL=${EXPERIMENTAL:-false}     # a development hook which allows us to disable code
 PROXY_WAIT=${PROXY_WAIT:-20}            # waiting at max 20 seconds for socket reply through proxy
@@ -244,8 +244,8 @@ TLS_DATA_FILE=""                        # mandatory fi
 PRINTF=""                               # which external printf to use. Empty presets the internal one, see #1130
 CIPHERS_BY_STRENGTH_FILE=""
 TLS_DATA_FILE=""                        # mandatory file for socket-based handshakes
-OPENSSL=""                              # ~/bin/openssl.$(uname).$(uname -m) if you run this from GitHub. Linux otherwise probably /usr/bin/openssl
-OPENSSL2=${OPENSSL2:-/usr/bin/openssl}  # This will be openssl version >=1.1.1 (auto determined) as opposed to openssl-bad (OPENSSL)
+OPENSSL="%%PREFIX%%/openssl-unsafe/bin/openssl"                              # ~/bin/openssl.$(uname).$(uname -m) if you run this from GitHub. Linux otherwise probably /usr/bin/openssl
+OPENSSL2=${OPENSSL2:-"%%OPENSSLBASE%%/bin/openssl"}  # This will be openssl version >=1.1.1 (auto determined) as opposed to openssl-bad (OPENSSL)
 OPENSSL2_HAS_TLS_1_3=false              # If we run with supplied binary AND $OPENSSL2 supports TLS 1.3 this will be set to true
 OPENSSL2_HAS_CHACHA20=false
 OPENSSL2_HAS_AES128_GCM=false
@@ -24940,7 +24940,6 @@ lets_roll() {
      mybanner
      check_proxy
      check4openssl_oldfarts
-     check_bsd_mount
      setup_lc_collate
 
      if "$do_display_only"; then
