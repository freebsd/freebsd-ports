--- library.mak.orig	2014-04-08 18:27:40.000000000 +0200
+++ library.mak	2014-03-23 17:47:44.000000000 +0100
@@ -80,7 +80,7 @@
 	$(Q)mkdir -p "$(INCINSTDIR)"
 	$$(INSTALL) -m 644 $$^ "$(INCINSTDIR)"
 
-install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(NAME).pc
+install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(NAME)-libav.pc
 	$(Q)mkdir -p "$(LIBDIR)/pkgconfig"
 	$$(INSTALL) -m 644 $$^ "$(LIBDIR)/pkgconfig"
 
