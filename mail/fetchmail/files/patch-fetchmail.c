commit c598c50ffda0dcac38b8bd01350dc6894a8efce4
Author: Matthias Andree <matthias.andree@gmx.de>
Date:   Wed Jun 11 01:46:07 2025 +0200

    Fix wolfSSL compilation failure around OPENSSL_DIR.
    
    Depending on wolfSSL version and configuration, it exposes a
    newer OpenSSL 1.1.x API of OpenSSL_version(), which passes its
    argument -- but that OpenSSL_version() function is documented
    as having been added in OpenSSL 3.0.  So let's not try using
    it with OPENSSL_DIR or OPENSSL_ENGINES_DIR arguments unless
    both OpenSSL >= 3.0 is found and both macros are defined,
    just in case...
    
    Reported by Corey Halpin,
    see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=287435

diff --git a/fetchmail.c b/fetchmail.c
index 97419f64..3c8e571d 100644
--- ./fetchmail.c
+++ b/fetchmail.c
@@ -343,9 +343,13 @@ int main(int argc, char **argv)
 		   "Run-time uses SSL library %#lx \"%s\"\n"),
 			OPENSSL_VERSION_NUMBER, OPENSSL_VERSION_TEXT,
 			OpenSSL_version_num(), OpenSSL_version(OPENSSL_VERSION));
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L // OpenSSL_version API in this form added in OpenSSL 3.0 according to manpage
+# if defined(OPENSSL_DIR) && defined(OPENSSL_ENGINES_DIR) // in-depth fix in case some OpenSSL freerider claims 3.x compat without delivering it
 	printf(GT_("OpenSSL: %s\nEngines: %s\n"),
 			OpenSSL_version(OPENSSL_DIR),
 			OpenSSL_version(OPENSSL_ENGINES_DIR));
+# endif
+#endif
 # if !HAVE_DECL_TLS1_3_VERSION || defined(OPENSSL_NO_TLS1_3)
 # error Your SSL/TLS library does not support TLS v1.3.
 # endif
