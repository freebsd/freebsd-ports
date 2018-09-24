--- SWIG/_m2crypto.i.orig	2018-02-24 13:54:59 UTC
+++ SWIG/_m2crypto.i
@@ -57,7 +57,8 @@ static PyObject *x509_store_verify_cb_fu
 #ifdef _WIN32
 %include <windows.i>
 #endif
+%include <openssl/e_os2.h>
 %include <openssl/safestack.h>
 
 /* Bring in LHASH_OF macro definition */
 /* XXX Can't include lhash.h where LHASH_OF is defined, because it includes
