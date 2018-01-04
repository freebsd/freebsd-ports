--- config.mk.orig	2017-07-10 22:46:01 UTC
+++ config.mk
@@ -249,7 +249,7 @@ ifeq ($(WITH_DOCS),yes)
 endif
 
 INSTALL?=install
-prefix=/usr/local
-mandir=${prefix}/share/man
-localedir=${prefix}/share/locale
+prefix=${PREFIX}
+mandir=${PREFIX}/share/man
+localedir=${PREFIX}/share/locale
 STRIP?=strip
