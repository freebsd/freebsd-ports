--- src/_cffi_src/openssl/fips.py.orig	2022-10-17 11:12:47 UTC
+++ src/_cffi_src/openssl/fips.py
@@ -17,11 +17,5 @@ int FIPS_mode(void);
 """
 
 CUSTOMIZATIONS = """
-#if CRYPTOGRAPHY_IS_LIBRESSL
-static const long Cryptography_HAS_FIPS = 0;
-int (*FIPS_mode_set)(int) = NULL;
-int (*FIPS_mode)(void) = NULL;
-#else
 static const long Cryptography_HAS_FIPS = 1;
-#endif
 """
