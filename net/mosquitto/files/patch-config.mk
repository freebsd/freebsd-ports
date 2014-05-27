--- config.mk.orig	2014-05-07 17:09:56.000000000 -0700
+++ config.mk	2014-05-07 17:10:31.000000000 -0700
@@ -213,6 +213,6 @@
 
 
 INSTALL?=install
-prefix=/usr/local
-mandir=${prefix}/share/man
-localedir=${prefix}/share/locale
+prefix=${PREFIX}
+mandir=${PREFIX}/share/man
+localedir=${PREFIX}/share/locale
