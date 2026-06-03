--- src/SWIG/_m2crypto.i.orig	2026-05-23 23:20:18 UTC
+++ src/SWIG/_m2crypto.i
@@ -70,6 +70,7 @@ static PyObject *x509_store_verify_cb_func;
 #ifdef _WIN32
 %include <windows.i>
 #endif
+%include <openssl/e_os2.h>
 %include <openssl/safestack.h>
 
 /* Bring in LHASH_OF macro definition */
