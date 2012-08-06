--- library.mak.orig	2012-08-06 10:08:41.247506447 +0200
+++ library.mak	2012-08-06 10:09:53.263505539 +0200
@@ -76,8 +76,8 @@
 	$(Q)mkdir -p "$(INCINSTDIR)"
 	$$(INSTALL) -m 644 $$^ "$(INCINSTDIR)"
 
 install-lib$(NAME)-pkgconfig: $(SUBDIR)lib$(NAME).pc
-	$(Q)mkdir -p "$(LIBDIR)/pkgconfig"
-	$$(INSTALL) -m 644 $$^ "$(LIBDIR)/pkgconfig"
+#	$(Q)mkdir -p "$(LIBDIR)/pkgconfig"
+#	$$(INSTALL) -m 644 $$^ "$(LIBDIR)/pkgconfig"
 
 uninstall-libs::
 	-$(RM) "$(SHLIBDIR)/$(SLIBNAME_WITH_MAJOR)" \
