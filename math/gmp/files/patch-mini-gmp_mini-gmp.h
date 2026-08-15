--- mini-gmp/mini-gmp.h.orig	2023-07-29 13:42:16 UTC
+++ mini-gmp/mini-gmp.h
@@ -297,7 +297,8 @@ int mpz_init_set_str (mpz_t, const char *, int);
   || defined (_ISO_STDIO_ISO_H)       /* Sun C++ */		\
   || defined (__STDIO_LOADED)         /* VMS */			\
   || defined (_STDIO)                 /* HPE NonStop */         \
-  || defined (__DEFINED_FILE)         /* musl */
+  || defined (__DEFINED_FILE)         /* musl */                \
+  || defined (__STDC_VERSION_STDIO_H__) /* C23 */
 size_t mpz_out_str (FILE *, int, const mpz_t);
 #endif
 
