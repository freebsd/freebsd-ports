--- SWIG/_m2crypto.i.orig	2020-01-30 08:17:01 UTC
+++ SWIG/_m2crypto.i
@@ -65,6 +65,7 @@ static PyObject *x509_store_verify_cb_func;
 #ifdef _WIN32
 %include <windows.i>
 #endif
+%include <openssl/e_os2.h>
 %include <openssl/safestack.h>
 
 /* Bring in LHASH_OF macro definition */
