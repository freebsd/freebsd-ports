Rename structs to avoid conflict with C API after NSS 3.58 changes to pk11pub.h
https://hg.mozilla.org/projects/nss/rev/6e3bc17f0508

In file included from src/py_nss.c:341:
src/py_nss.h:126:3: error: typedef redefinition with different types ('struct RSAPublicKey' vs 'struct RSAPublicKeyStr')
} RSAPublicKey;
  ^
/usr/local/include/nss/blapit.h:281:32: note: previous definition is here
typedef struct RSAPublicKeyStr RSAPublicKey;
                               ^
In file included from src/py_nss.c:341:
src/py_nss.h:136:3: error: typedef redefinition with different types ('struct DSAPublicKey' vs 'struct DSAPublicKeyStr')
} DSAPublicKey;
  ^
/usr/local/include/nss/blapit.h:323:32: note: previous definition is here
typedef struct DSAPublicKeyStr DSAPublicKey;
                               ^

--- src/py_nss.h.orig	2016-02-16 16:40:14 UTC
+++ src/py_nss.h
@@ -119,6 +119,7 @@ typedef struct {
 /* ============================ RSAPublicKey Class ========================== */
 /* ========================================================================== */
 
+#define RSAPublicKey PyRSAPublicKey
 typedef struct {
     PyObject_HEAD
     PyObject *py_modulus;
@@ -129,6 +130,7 @@ typedef struct {
 /* ============================ DSAPublicKey Class ========================== */
 /* ========================================================================== */
 
+#define DSAPublicKey PyDSAPublicKey
 typedef struct {
     PyObject_HEAD
     PyObject *py_pqg_params;
