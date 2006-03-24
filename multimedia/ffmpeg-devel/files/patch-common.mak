--- common.mak.orig	Thu Mar 23 14:55:10 2006
+++ common.mak	Thu Mar 23 15:01:13 2006
@@ -71,27 +71,20 @@
 install-libs: $(INSTLIBTARGETS)
 
 install-lib-shared: $(SLIBNAME)
-	install -d "$(libdir)"
 ifeq ($(CONFIG_WIN32),yes)
 	install $(INSTALLSTRIP) -m 755 $(SLIBNAME) "$(prefix)"
 else
-	install $(INSTALLSTRIP) -m 755 $(SLIBNAME) \
-		$(libdir)/$(SLIBNAME_WITH_VERSION)
-	ln -sf $(SLIBNAME_WITH_VERSION) \
-		$(libdir)/$(SLIBNAME_WITH_MAJOR)
-	ln -sf $(SLIBNAME_WITH_VERSION) \
-		$(libdir)/$(SLIBNAME)
+	${BSD_INSTALL_DATA} $(SLIBNAME) \
+		$(libdir)
 endif
 
 install-lib-static: $(LIB)
-	install -d "$(libdir)"
-	install -m 644 $(LIB) "$(libdir)"
+	${BSD_INSTALL_DATA} $(LIB) "$(libdir)"
 
 install-headers:
-	install -d "$(incdir)"
-	install -d "$(libdir)/pkgconfig"
-	install -m 644 $(addprefix "$(SRC_DIR)"/,$(HEADERS)) "$(incdir)"
-	install -m 644 $(BUILD_ROOT)/lib$(NAME).pc "$(libdir)/pkgconfig"
+	${INSTALL} -d "$(incdir)"
+	${BSD_INSTALL_DATA} $(addprefix "$(SRC_DIR)"/,$(HEADERS)) "$(incdir)"
+	${BSD_INSTALL_DATA} $(BUILD_ROOT)/lib$(NAME).pc "$(prefix)/libdata/pkgconfig"
 
 #
 # include dependency files if they exist
