--- Mk/mk-freebsd.mk.bak	Fri Feb 13 01:05:08 2004
+++ Mk/mk-freebsd.mk	Mon Jul 11 16:45:09 2005
@@ -26,7 +26,7 @@
 install_bin=$(installdir)/bin
 install_etc=$(installdir)/etc
 install_lib=$(installdir)/lib
-install_template=$(installdir)/template
+install_template=$(installdir)/share/tspc2/template
 install_man=$(installdir)/man
 subdirs=src/net src/lib src/tsp src/xml platform/freebsd template conf man
 ifname=gif0
