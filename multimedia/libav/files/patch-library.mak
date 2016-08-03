--- library.mak.orig	2016-05-25 00:36:32 UTC
+++ library.mak
@@ -80,7 +80,7 @@ install-lib$(NAME)-headers: $(addprefix 
 	$(Q)mkdir -p "$(INCINSTDIR)"
 	$$(INSTALL) -m 644 $$^ "$(INCINSTDIR)"
 
-install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(NAME).pc
+install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(NAME)-libav.pc
 	$(Q)mkdir -p "$(LIBDIR)/pkgconfig"
 	$$(INSTALL) -m 644 $$^ "$(LIBDIR)/pkgconfig"
 
