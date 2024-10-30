Cherry-pick from upstream 8f00c607, see 
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=282413#c4

--- tls-aux.h.orig	2024-08-18 17:42:19 UTC
+++ tls-aux.h
@@ -18,12 +18,6 @@
 # ifdef LIBWOLFSSL_VERSION_HEX
 #  define USING_WOLFSSL 1
 #  define OSSL110_API 1
-#  ifndef OPENSSL_COMPATIBLE_DEFAULTS
-#   error "wolfSSL was compiled without -DOPENSSL_COMPATIBLE_DEFAULTS. Recompile and reinstall wolfSSL!"
-#  endif
-#  ifndef HAVE_EX_DATA
-#   error "wolfSSL was configured without --enable-context-extra-user-data. Recompile and reinstall wolfSSL!"
-#  endif
 # else
 #  if OPENSSL_VERSION_NUMBER < 0x1010000fL
 #   undef OSSL110_API
