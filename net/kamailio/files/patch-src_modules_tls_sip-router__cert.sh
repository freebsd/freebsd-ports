--- src/modules/tls/sip-router_cert.sh.orig	2017-04-21 12:46:06 UTC
+++ src/modules/tls/sip-router_cert.sh
@@ -197,5 +197,6 @@ if [ $? != 0 ] ; then
 else
 	echo "Private key stored in '$DIR/$KEY_FILENAME'."
 	echo "Certificate stored in '$DIR/$CERT_FILENAME'."
+	rm ~/.rnd
 	exit 0;
 fi
