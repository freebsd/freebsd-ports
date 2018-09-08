--- testssl.sh.orig	2018-09-08 11:00:02 UTC
+++ testssl.sh
@@ -188,6 +188,9 @@ TERM_CURRPOS=0                                        
 ########### Defining (and presetting) variables which can be changed
 #
 # Following variables make use of $ENV and can be used like "OPENSSL=<myprivate_path_to_openssl> ./testssl.sh <URI>"
+if [[ -z "$OPENSSL" ]] ; then
+     OPENSSL=PREFIX/openssl-unsafe/bin/openssl
+fi
 declare -x OPENSSL OPENSSL_TIMEOUT
 PHONE_OUT=${PHONE_OUT:-false}           # Whether testssl can retrieve CRLs and OCSP
 FAST_SOCKET=${FAST_SOCKET:-false}       # EXPERIMENTAL feature to accelerate sockets -- DO NOT USE it for production
