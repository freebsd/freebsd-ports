--- ./supportlibs/pegmarkdown/pegmarkdown.pro.orig	2013-12-11 16:08:42.000000000 +0100
+++ ./supportlibs/pegmarkdown/pegmarkdown.pro	2013-12-11 16:09:21.000000000 +0100
@@ -55,6 +55,7 @@
 ################################# FreeBSD ##########################################
 
 freebsd-* {
+        QMAKE_CC = cc
 		DESTDIR = lib
 }
 
