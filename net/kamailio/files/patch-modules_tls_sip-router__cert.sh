--- modules/tls/sip-router_cert.sh.orig	2015-07-20 13:16:26 UTC
+++ modules/tls/sip-router_cert.sh
@@ -197,5 +197,6 @@ if [ $? != 0 ] ; then
 else
 	echo "Private key stored in '$DIR/$KEY_FILENAME'."
 	echo "Certificate stored in '$DIR/$CERT_FILENAME'."
+	rm ~/.rnd
 	exit 0;
 fi
