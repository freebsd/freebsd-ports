--- testssl.sh.orig	2018-03-17 15:02:25 UTC
+++ testssl.sh
@@ -175,6 +175,9 @@ TERM_CURRPOS=0                          
 ## CONFIGURATION PART ##
 # following variables make use of $ENV, e.g. OPENSSL=<myprivate_path_to_openssl> ./testssl.sh <host>
 # 0 means (normally) true here. Some of the variables are also accessible with a command line switch, see --help
+if [[ -z "$OPENSSL" ]] ; then
+     OPENSSL=PREFIX/openssl-unsafe/bin/openssl
+fi
 declare -x OPENSSL OPENSSL_TIMEOUT
 FAST_SOCKET=${FAST_SOCKET:-false}       # EXPERIMENTAL feature to accelerate sockets -- DO NOT USE it for production
 COLOR=${COLOR:-2}                       # 2: Full color, 1: b/w+positioning, 0: no ESC at all
@@ -6221,7 +6224,7 @@ certificate_info() {
           # best we are able to do under OpenBSD
           days2expire=""
      else
-          days2expire=$(( $(parse_date "$enddate" "+%s" "%F %H:%M %z") - $(LC_ALL=C date "+%s") ))    # in seconds
+          days2expire=$(( $(parse_date "$enddate" "+%s" "%F %H:%M") - $(LC_ALL=C date "+%s") ))    # in seconds
           days2expire=$((days2expire  / 3600 / 24 ))
 
           if grep -q "^Let's Encrypt Authority" <<< "$issuer_CN"; then          # we take the half of the thresholds for LE certificates
