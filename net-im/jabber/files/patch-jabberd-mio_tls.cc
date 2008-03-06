--- jabberd/mio_tls.cc.orig	2008-03-06 10:21:01.669677189 +0100
+++ jabberd/mio_tls.cc	2008-03-06 10:35:04.744064592 +0100
@@ -612,7 +612,7 @@
 	    }
 
 	    // load OpenPGP key/certificate
-	    ret = gnutls_certificate_set_openpgp_key_file(current_credentials, pubfile, privfile);
+	    ret = gnutls_certificate_set_openpgp_key_file(current_credentials, pubfile, privfile, GNUTLS_OPENPGP_FMT_BASE64);
 	    if (ret < 0) {
 		log_error(NULL, "Error loading OpenPGP key pub=%s/priv=%s: %s", pubfile, privfile, gnutls_strerror(ret));
 		continue;
@@ -631,7 +631,7 @@
 	    }
 
 	    // load the OpenPGP keyring
-	    ret = gnutls_certificate_set_openpgp_keyring_file(current_credentials, file);
+	    ret = gnutls_certificate_set_openpgp_keyring_file(current_credentials, file, GNUTLS_OPENPGP_FMT_BASE64);
 	    if (ret < 0) {
 		log_error(NULL, "Error loading OpenPGP keyring %s: %s", file, gnutls_strerror(ret));
 		continue;
@@ -640,23 +640,6 @@
 	    continue;
 	}
 
-	// load GnuPG trustdb
-	if (j_strcmp(xmlnode_get_localname(cur), "trustdb") == 0) {
-	    char const *const file = xmlnode_get_data(cur);
-
-	    if (file == NULL) {
-		log_warn(NULL, "Initializing TLS subsystem: <trustdb/> element inside the TLS configuration, that does not contain a file-name.");
-		continue;
-	    }
-
-	    // load the GnuPG trustdb
-	    ret = gnutls_certificate_set_openpgp_trustdb(current_credentials, file);
-	    if (ret < 0) {
-		log_error(NULL, "Error loading GnuPG trustdb %s: %s", file, gnutls_strerror(ret));
-		continue;
-	    }
-	}
-
 	// setup protocols to use
 	if (j_strcmp(xmlnode_get_localname(cur), "protocols") == 0) {
 	    char const *const protocols_data = xmlnode_get_data(cur);
