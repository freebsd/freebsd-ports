--- doc/mkcert.sh	Tue Apr 15 14:28:24 2003
+++ mkcert.sh.new	Tue Apr 15 14:28:52 2003
@@ -4,7 +4,7 @@
 # Edit dovecot-openssl.cnf before running this.
 
 OPENSSL=${OPENSSL-openssl}
-SSLDIR=${SSLDIR-/etc/ssl}
+SSLDIR=${SSLDIR-%%SSLDIR%%}
 OPENSSLCONFIG=${OPENSSLCONFIG-dovecot-openssl.cnf}
 
 CERTFILE=$SSLDIR/certs/imapd.pem
