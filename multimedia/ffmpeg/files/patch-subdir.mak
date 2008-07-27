--- subdir.mak.orig	2008-07-27 15:57:37.873013462 -0500
+++ subdir.mak	2008-07-27 15:58:54.041106334 -0500
@@ -54,9 +54,9 @@
 
 install-headers::
 	install -d "$(INCINSTDIR)"
-	install -d "$(LIBDIR)/pkgconfig"
+	install -d "$(prefix)/libdata/pkgconfig"
 	install -m 644 $(addprefix "$(SRC_DIR)"/,$(HEADERS)) "$(INCINSTDIR)"
-	install -m 644 $(BUILD_ROOT)/lib$(NAME)/lib$(NAME).pc "$(LIBDIR)/pkgconfig"
+	install -m 644 $(BUILD_ROOT)/lib$(NAME)/lib$(NAME).pc "$(prefix)/libdata/pkgconfig"
 
 uninstall-libs::
 	-rm -f "$(SHLIBDIR)/$(SLIBNAME_WITH_MAJOR)" \
