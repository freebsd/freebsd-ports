--- config.mk.orig	2015-05-07 13:21:22 UTC
+++ config.mk
@@ -241,7 +241,7 @@ ifeq ($(WITH_DOCS),yes)
 endif
 
 INSTALL?=install
-prefix=/usr/local
-mandir=${prefix}/share/man
-localedir=${prefix}/share/locale
+prefix=${PREFIX}
+mandir=${PREFIX}/share/man
+localedir=${PREFIX}/share/locale
 STRIP?=strip
