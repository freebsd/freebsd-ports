--- src/SWIG/_m2crypto.i.orig	2026-02-07 22:38:57 UTC
+++ src/SWIG/_m2crypto.i
@@ -43,11 +43,6 @@ typedef unsigned __int64 uint64_t;
 %}
 
 %{
-#if defined __GNUC__ && __GNUC__ < 5
-PRAGMA_IGNORE_UNUSED_LABEL
-PRAGMA_WARN_STRICT_PROTOTYPES
-#endif
-
 #include <openssl/err.h>
 #include <openssl/rand.h>
 #include <_lib.h>
@@ -67,6 +62,7 @@ static PyObject *x509_store_verify_cb_func;
 #ifdef _WIN32
 %include <windows.i>
 #endif
+%include <openssl/e_os2.h>
 %include <openssl/safestack.h>
 
 /* Bring in LHASH_OF macro definition */
