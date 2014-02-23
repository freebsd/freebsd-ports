--- jabberd/mio_tls.cc.orig	2008-03-06 10:21:01.669677189 +0100
+++ jabberd/mio_tls.cc	2008-03-06 10:35:04.744064592 +0100
@@ -39,7 +39,6 @@
 #include <set>
 #include <string>
 #include <sstream>
-#include <gcrypt.h>
 #include <vector>
 #include <list>
 #include <iostream>
@@ -612,7 +611,7 @@
 	    }
 
 	    // load OpenPGP key/certificate
-	    ret = gnutls_certificate_set_openpgp_key_file(current_credentials, pubfile, privfile);
+	    ret = gnutls_certificate_set_openpgp_key_file(current_credentials, pubfile, privfile, GNUTLS_OPENPGP_FMT_BASE64);
 	    if (ret < 0) {
 		log_error(NULL, "Error loading OpenPGP key pub=%s/priv=%s: %s", pubfile, privfile, gnutls_strerror(ret));
 		continue;
@@ -631,7 +630,7 @@
 	    }
 
 	    // load the OpenPGP keyring
-	    ret = gnutls_certificate_set_openpgp_keyring_file(current_credentials, file);
+	    ret = gnutls_certificate_set_openpgp_keyring_file(current_credentials, file, GNUTLS_OPENPGP_FMT_BASE64);
 	    if (ret < 0) {
 		log_error(NULL, "Error loading OpenPGP keyring %s: %s", file, gnutls_strerror(ret));
 		continue;
@@ -640,23 +639,6 @@
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
@@ -916,7 +898,7 @@
     /* load asn1 tree to be used by libtasn1 */
     ret = asn1_array2tree(subjectAltName_asn1_tab, &mio_tls_asn1_tree, NULL);
     if (ret != ASN1_SUCCESS) {
-	std::cerr << "Error preparing the libtasn1 library: " << libtasn1_strerror(ret) << std::endl;
+	std::cerr << "Error preparing the libtasn1 library: " << asn1_strerror(ret) << std::endl;
 	return false;
 	/* XXX we have to delete the structure on shutdown using asn1_delete_structure(&mio_tls_asn1_tree) */
     }
@@ -1684,14 +1666,14 @@
 		    /* init subjectAltName_element */
 		    ret = asn1_create_element(mio_tls_asn1_tree, "PKIX1.SubjectAltName", &subjectAltName_element);
 		    if (ret != ASN1_SUCCESS) {
-			log_warn(log_id.c_str(), "error creating asn1 element for PKIX1.SubjectAltName: %s (%s)", libtasn1_strerror(ret), cert_subject.c_str());
+			log_warn(log_id.c_str(), "error creating asn1 element for PKIX1.SubjectAltName: %s (%s)", asn1_strerror(ret), cert_subject.c_str());
 			break;
 		    }
 
 		    /* decode the extension */
 		    ret = asn1_der_decoding(&subjectAltName_element, subjectAltName, subjectAltName_size, NULL);
 		    if (ret != ASN1_SUCCESS) {
-			log_warn(log_id.c_str(), "error DER decoding subjectAltName extension: %s (%s)", libtasn1_strerror(ret), cert_subject.c_str());
+			log_warn(log_id.c_str(), "error DER decoding subjectAltName extension: %s (%s)", asn1_strerror(ret), cert_subject.c_str());
 			asn1_delete_structure(&subjectAltName_element);
 			break;
 		    }
@@ -1712,7 +1694,7 @@
 			    break;
 			}
 			if (ret != ASN1_SUCCESS) {
-			    log_notice(log_id.c_str(), "error accessing type for %s in subjectAltName: %s (%s)", cnt_string, libtasn1_strerror(ret), cert_subject.c_str());
+			    log_notice(log_id.c_str(), "error accessing type for %s in subjectAltName: %s (%s)", cnt_string, asn1_strerror(ret), cert_subject.c_str());
 			    break;
 			}
 
@@ -1732,7 +1714,7 @@
 
 				ret = asn1_read_value(subjectAltName_element, access_string, dNSName, &dNSName_len);
 				if (ret != ASN1_SUCCESS) {
-				    log_notice(log_id.c_str(), "error accessing %s in subjectAltName: %s (%s)", access_string, libtasn1_strerror(ret), cert_subject.c_str());
+				    log_notice(log_id.c_str(), "error accessing %s in subjectAltName: %s (%s)", access_string, asn1_strerror(ret), cert_subject.c_str());
 				    break;
 				}
 
@@ -1772,7 +1754,7 @@
 			    /* get the OID of the otherName */
 			    ret = asn1_read_value(subjectAltName_element, access_string_type, otherNameType, &otherNameType_len);
 			    if (ret != ASN1_SUCCESS) {
-				log_notice(log_id.c_str(), "error accessing type information %s in subjectAltName: %s (%s)", access_string_type, libtasn1_strerror(ret), cert_subject.c_str());
+				log_notice(log_id.c_str(), "error accessing type information %s in subjectAltName: %s (%s)", access_string_type, asn1_strerror(ret), cert_subject.c_str());
 				break;
 			    }
 
@@ -1785,7 +1767,7 @@
 			    /* get the value of the otherName */
 			    ret = asn1_read_value(subjectAltName_element, access_string_value, otherNameValue, &otherNameValue_len);
 			    if (ret != ASN1_SUCCESS) {
-				log_notice(log_id.c_str(), "error accessing value of othername %s in subjectAltName: %s (%s)", access_string_value, libtasn1_strerror(ret), cert_subject.c_str());
+				log_notice(log_id.c_str(), "error accessing value of othername %s in subjectAltName: %s (%s)", access_string_value, asn1_strerror(ret), cert_subject.c_str());
 				break;
 			    }
 
@@ -1799,21 +1781,21 @@
 
 				ret = asn1_create_element(mio_tls_asn1_tree, "PKIX1.DirectoryString", &directoryString_element);
 				if (ret != ASN1_SUCCESS) {
-				    log_notice(log_id.c_str(), "error creating DirectoryString element: %s (%s)", libtasn1_strerror(ret), cert_subject.c_str());
+				    log_notice(log_id.c_str(), "error creating DirectoryString element: %s (%s)", asn1_strerror(ret), cert_subject.c_str());
 				    asn1_delete_structure(&directoryString_element);
 				    break;
 				}
 
 				ret = asn1_der_decoding(&directoryString_element, otherNameValue, otherNameValue_len, NULL);
 				if (ret != ASN1_SUCCESS) {
-				    log_notice(log_id.c_str(), "error decoding DirectoryString: %s (%s)", libtasn1_strerror(ret), cert_subject.c_str());
+				    log_notice(log_id.c_str(), "error decoding DirectoryString: %s (%s)", asn1_strerror(ret), cert_subject.c_str());
 				    asn1_delete_structure(&directoryString_element);
 				    break;
 				}
 
 				ret = asn1_read_value(directoryString_element, "utf8String", thisIdOnXMPPaddr, &thisIdOnXMPPaddr_len);
 				if (ret != ASN1_SUCCESS) {
-				    log_notice(log_id.c_str(), "error accessing utf8String of DirectoryString: %s (%s)", libtasn1_strerror(ret), cert_subject.c_str());
+				    log_notice(log_id.c_str(), "error accessing utf8String of DirectoryString: %s (%s)", asn1_strerror(ret), cert_subject.c_str());
 				    asn1_delete_structure(&directoryString_element);
 				    break;
 				}
