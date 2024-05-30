https://www.openssl.org/docs/man3.0/man7/migration_guide.html#Removal-of-function-code-from-the-error-codes
states that the ERR_GET_FUNC() "macro" was removed, so follow suit:

--- src/_cffi_src/openssl/err.py.orig	2021-08-24 17:17:17 UTC
+++ src/_cffi_src/openssl/err.py
@@ -39,7 +39,6 @@ int ERR_GET_LIB(unsigned long);
 void ERR_put_error(int, int, int, const char *, int);
 
 int ERR_GET_LIB(unsigned long);
-int ERR_GET_FUNC(unsigned long);
 int ERR_GET_REASON(unsigned long);
 
 """
