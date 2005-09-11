--- src/spf_example/spf_example.c.orig	Mon Mar 28 14:17:20 2005
+++ src/spf_example/spf_example.c	Mon Mar 28 14:22:46 2005
@@ -90,17 +90,17 @@
 	"\n"
 	"Valid data options are:\n"
 	"	-i <IP address>			The IP address that is sending email\n"
-	"	-s <email address>		 The email address used as the\n"
-	"							   envelope-from.  If no username (local\n"
-	"							   part) is given, 'postmaster' will be\n"
-	"							   assumed.\n"
-	"	-r <email address>		 [optional] The email address used as\n"
-	"							   the envelope-to email address, for\n"
-	"							   secondary-MX checking.\n"
-	"	-h <domain name>		   The domain name given on the SMTP HELO\n"
-	"							   command.  This is only needed if the\n"
-	"							   -sender option is not given.\n"
-	"	-d [debug level]		   debug level.\n"
+	"	-s <email address>		The email address used as the\n"
+	"					envelope-from.  If no username (local\n"
+	"					part) is given, 'postmaster' will be\n"
+	"					assumed.\n"
+	"	-r <email address>		[optional] The email address used as\n"
+	"					the envelope-to email address, for\n"
+	"					secondary-MX checking.\n"
+	"	-h <domain name>		The domain name given on the SMTP HELO\n"
+	"					command.  This is only needed if the\n"
+	"					-sender option is not given.\n"
+	"	-d [debug level]		debug level.\n"
 	);
 }
 
@@ -206,7 +206,7 @@
 	 * destroyed when you are finished.
 	 */
 
-	spf_server = SPF_server_new(SPF_DNS_CACHE, 1);
+	spf_server = SPF_server_new(SPF_DNS_CACHE, opt_debug);
 
 	if (spf_server == NULL) {
 		fprintf( stderr, "SPF_create_config failed.\n" );
@@ -264,10 +264,24 @@
 	 * message.
 	 */
 
-	if ( SPF_request_set_helo_dom( spf_request, opt_helo ) ) {
-		printf( "Invalid HELO domain.\n" );
-		res = 255;
-		goto error;
+	if (opt_helo == NULL) {
+		if (opt_sender != NULL) {
+			if (strstr(opt_sender, "@") != NULL) {
+				opt_helo = strdup(strstr(opt_sender, "@") + 1);
+
+				if ( SPF_request_set_helo_dom( spf_request, opt_helo ) ) {
+					printf( "Invalid HELO domain.\n" );
+					res = 255;
+					goto error;
+				}
+			}
+		}
+	} else {
+		if ( SPF_request_set_helo_dom( spf_request, opt_helo ) ) {
+			printf( "Invalid HELO domain.\n" );
+			res = 255;
+			goto error;
+		}
 	}
 
 	/*
