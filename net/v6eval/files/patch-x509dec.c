--- bin/x509dec/x509dec.c	2005-05-30 19:17:31.000000000 +0900
+++ bin/x509dec/x509dec.c	2008-01-01 06:02:24.000000000 +0900
@@ -244,13 +244,13 @@ x509dec_on_evp(const X509 *const x509)
 
 	TAILQ_INIT(&head);
 
-	if(!((unsigned char *)pubkey =
+	if(!(pubkey =
 		X509dec_get_pubkey(x509, &pubkeylen))) {
 
 		return(x509dec_on_evp_return(false, pubkey, subject_name));
 	}
 
-	if(!((unsigned char *)subject_name =
+	if(!(subject_name =
 		X509dec_get_subject_name(x509, (int *)&subject_namelen))) {
 
 		return(x509dec_on_evp_return(false, pubkey, subject_name));
