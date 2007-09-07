--- Mk/mk-freebsd.mk.orig	2006-09-23 01:06:20.000000000 +0200
+++ Mk/mk-freebsd.mk	2007-07-12 17:58:04.000000000 +0200
@@ -16,7 +16,7 @@
 install_bin=$(installdir)/bin
 install_etc=$(installdir)/etc
 install_lib=$(installdir)/lib
-install_template=$(installdir)/template
+install_template=$(installdir)/share/gateway6
 install_man=$(installdir)/man
 subdirs=src/net src/lib src/tsp src/xml platform/unix-common platform/freebsd template conf man
 ifname=gif0
