--- librepo/librepo.pc.cmake.orig	2024-11-04 16:54:08 UTC
+++ librepo/librepo.pc.cmake
@@ -6,7 +6,7 @@ Requires: glib-2.0
 Description: Repodata downloading library.
 Version: @VERSION@
 Requires: glib-2.0
-Requires.private: libcurl openssl libxml-2.0 @PKGCONF_DEPENDENCY_ZCK@
+Requires.private: libcurl libxml-2.0 @PKGCONF_DEPENDENCY_ZCK@
 Libs: -L${libdir} -lrepo
 Libs.private: -lgpgme -lgpg-error
 Cflags: -I${includedir} -D_FILE_OFFSET_BITS=64
