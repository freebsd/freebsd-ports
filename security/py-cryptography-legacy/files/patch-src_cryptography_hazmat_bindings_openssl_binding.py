https://www.openssl.org/docs/man3.0/man7/migration_guide.html#Removal-of-function-code-from-the-error-codes
states that the code is always 0, so do just that and forgo the call of a
nonexistent function.

--- src/cryptography/hazmat/bindings/openssl/binding.py.orig	2021-08-24 17:17:17 UTC
+++ src/cryptography/hazmat/bindings/openssl/binding.py
@@ -43,7 +43,7 @@ def _consume_errors(lib):
             break
 
         err_lib = lib.ERR_GET_LIB(code)
-        err_func = lib.ERR_GET_FUNC(code)
+        err_func = 0
         err_reason = lib.ERR_GET_REASON(code)
 
         errors.append(_OpenSSLError(code, err_lib, err_func, err_reason))
