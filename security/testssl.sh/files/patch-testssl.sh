--- testssl.sh.orig	2019-12-11 11:41:31 UTC
+++ testssl.sh
@@ -190,6 +190,9 @@ TERM_CURRPOS=0                                        
 ########### Defining (and presetting) variables which can be changed
 #
 # Following variables make use of $ENV and can be used like "OPENSSL=<myprivate_path_to_openssl> ./testssl.sh <URI>"
+if [[ -z "$OPENSSL" ]] ; then
+     OPENSSL=PREFIX/openssl-unsafe/bin/openssl
+fi
 declare -x OPENSSL
 OPENSSL_TIMEOUT=${OPENSSL_TIMEOUT:-""}  # Default connect timeout with openssl before we call the server side unreachable
 CONNECT_TIMEOUT=${CONNECT_TIMEOUT:-""}  # Default connect timeout with sockets before we call the server side unreachable
