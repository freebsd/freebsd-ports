--- Makefile.PL.orig	2013-05-25 17:07:14 UTC
+++ Makefile.PL
@@ -41,6 +41,7 @@ check_lib_or_exit(
 # SHA-512)
 check_lib_or_exit(
     function => 'if (gcry_check_version("1.3.0")) return 0; else return 1;',
+    header => [qw(gcrypt.h)],
     lib => [qw(gcrypt)],
     libpath => $gcrypt_libpath
 );
