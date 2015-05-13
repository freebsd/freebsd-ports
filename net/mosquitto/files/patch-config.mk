--- config.mk.orig	2014-10-08 21:50:07 UTC
+++ config.mk
@@ -213,7 +213,7 @@ endif
 
 
 INSTALL?=install
-prefix=/usr/local
-mandir=${prefix}/share/man
-localedir=${prefix}/share/locale
+prefix=${PREFIX}
+mandir=${PREFIX}/share/man
+localedir=${PREFIX}/share/locale
 STRIP?=strip
