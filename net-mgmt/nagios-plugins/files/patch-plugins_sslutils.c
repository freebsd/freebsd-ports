--- plugins/sslutils.c.orig	2017-04-19 16:03:12 UTC
+++ plugins/sslutils.c
@@ -211,9 +211,6 @@ int np_net_ssl_check_cert(int days_till_
 	int time_remaining;
 	time_t tm_t;
 
-	// Prefix whatever we're about to print with SSL
-	printf("SSL ");
-
 	certificate=SSL_get_peer_certificate(s);
 	if (!certificate) {
 		printf("%s\n",_("CRITICAL - Cannot retrieve server certificate."));
@@ -304,7 +301,7 @@ int np_net_ssl_check_cert(int days_till_
 		else
 			status = STATE_CRITICAL;
 	} else {
-		printf(_("OK - Certificate '%s' will expire on %s. "), cn, timestamp);
+		printf(_("OK - Certificate '%s' will expire on %s.\n"), cn, timestamp);
 		status = STATE_OK;
 	}
 	X509_free(certificate);
