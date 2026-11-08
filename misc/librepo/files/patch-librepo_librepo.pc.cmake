--- librepo/librepo.pc.cmake.orig	2026-09-09 07:53:37 UTC
+++ librepo/librepo.pc.cmake
@@ -6,7 +6,7 @@ Requires: glib-2.0
 Description: Repodata downloading library.
 Version: @VERSION@
 Requires: glib-2.0
-Requires.private: libcurl openssl libxml-2.0 gio-2.0 @PKGCONF_DEPENDENCY_ZCK@ @PKGCONF_REQUIRES_SELINUX@
+Requires.private: libcurl libxml-2.0 gio-2.0 @PKGCONF_DEPENDENCY_ZCK@ @PKGCONF_REQUIRES_SELINUX@
 Libs: -L${libdir} -lrepo
 Libs.private: -lgpgme -lgpg-error
 Cflags: -I${includedir} -D_FILE_OFFSET_BITS=64
