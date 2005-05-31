--- autoconf/make/vars.mk.orig	Wed Apr 13 21:33:12 2005
+++ autoconf/make/vars.mk	Wed Apr 13 21:35:10 2005
@@ -24,7 +24,7 @@
 INSTALL_DATA = @INSTALL_DATA@
 UNINSTALL = rm -f
 
-LDFLAGS = -r
+LDFLAGS = @LDFLAGS@
 DEFS = @DEFS@
 CFLAGS = @CFLAGS@
 CPPFLAGS = @CPPFLAGS@ -I$(srcdir)/src/include -Isrc/include $(DEFS)
