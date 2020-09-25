--- librepo/librepo.pc.cmake.orig	2020-09-20 19:51:54 UTC
+++ librepo/librepo.pc.cmake
@@ -6,7 +6,7 @@ Name: librepo
 Description: Repodata downloading library.
 Version: @VERSION@
 Requires: glib-2.0
-Requires.private: libcurl openssl libxml-2.0
+Requires.private: libcurl libxml-2.0
 Libs: -L${libdir} -lrepo
 Libs.private: -lgpgme -lgpg-error
 Cflags: -I${includedir} -D_FILE_OFFSET_BITS=64
