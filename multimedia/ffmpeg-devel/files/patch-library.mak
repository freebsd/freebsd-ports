--- library.mak.orig	2012-10-13 10:22:27.000000000 +0200
+++ library.mak	2012-10-13 10:57:11.333238227 +0200
@@ -76,9 +76,9 @@
 	$(Q)mkdir -p "$(INCINSTDIR)"
 	$$(INSTALL) -m 644 $$^ "$(INCINSTDIR)"
 
-install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(NAME).pc
-	$(Q)mkdir -p "$(LIBDIR)/pkgconfig"
-	$$(INSTALL) -m 644 $$^ "$(LIBDIR)/pkgconfig"
+install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(NAME)$(BUILDSUF).pc
+	$(Q)mkdir -p "$(prefix)/libdata/pkgconfig"
+	$$(INSTALL) -m 644 $$^ "$(prefix)/libdata/pkgconfig"
 
 uninstall-libs::
 	-$(RM) "$(SHLIBDIR)/$(SLIBNAME_WITH_MAJOR)" \
@@ -90,7 +90,7 @@
 
 uninstall-headers::
 	$(RM) $(addprefix "$(INCINSTDIR)/",$(HEADERS) $(BUILT_HEADERS))
-	$(RM) "$(LIBDIR)/pkgconfig/lib$(NAME).pc"
+	$(RM) "$(prefix)/libdata/pkgconfig/lib$(NAME).pc"
 	-rmdir "$(INCINSTDIR)"
 endef
 
