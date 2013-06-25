--- library.mak.orig	2012-09-28 03:37:35.000000000 +0200
+++ library.mak	2012-10-12 21:38:55.732664096 +0200
@@ -74,9 +74,9 @@
 	$(Q)mkdir -p "$(INCINSTDIR)"
 	$$(INSTALL) -m 644 $$^ "$(INCINSTDIR)"
 
 install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(FULLNAME).pc
-	$(Q)mkdir -p "$(LIBDIR)/pkgconfig"
-	$$(INSTALL) -m 644 $$^ "$(LIBDIR)/pkgconfig"
+	$(Q)mkdir -p "$(prefix)/libdata/pkgconfig"
+	$$(INSTALL) -m 644 $$^ "$(prefix)/libdata/pkgconfig"
 
 uninstall-libs::
 	-$(RM) "$(SHLIBDIR)/$(SLIBNAME_WITH_MAJOR)" \
@@ -88,7 +88,7 @@
 
 uninstall-headers::
 	$(RM) $(addprefix "$(INCINSTDIR)/",$(HEADERS) $(BUILT_HEADERS))
-	$(RM) "$(LIBDIR)/pkgconfig/lib$(FULLNAME).pc"
+	$(RM) "$(prefix)/libdata/pkgconfig/lib$(FULLNAME).pc"
 	-rmdir "$(INCINSTDIR)"
 endef
 
