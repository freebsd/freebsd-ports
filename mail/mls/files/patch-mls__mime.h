--- mls_mime.h.orig	2021-11-01 09:11:54 UTC
+++ mls_mime.h
@@ -21,7 +21,7 @@
 #ifndef	_MLS_MIME_H
 #define	_MLS_MIME_H	1
 
-regex_t r_qp, r_base64, r_hex;
+extern regex_t r_qp, r_base64, r_hex;
 
 /* ********************************************* FUNCTION DECLARATIONS *** */
 int base64_table(char *lookup);
