
$FreeBSD$

--- libs.mk.orig
+++ libs.mk
@@ -209,7 +209,7 @@
     $(addprefix $(BUILD_PFX),$(notdir $(LIBVPX_SO_SYMLINKS))),\
     $(BUILD_PFX)$(LIBVPX_SO)))
 $(eval $(call libvpx_symlink_template,\
-    $(addprefix $(DIST_DIR)/,$(LIBVPX_SO_SYMLINKS)),\
+    $(addprefix $(DESTDIR)/$(DIST_DIR)/,$(LIBVPX_SO_SYMLINKS)),\
     $(DIST_DIR)/$(LIBSUBDIR)/$(LIBVPX_SO)))
 
 INSTALL-LIBS-$(CONFIG_SHARED) += $(LIBVPX_SO_SYMLINKS)
@@ -232,8 +232,8 @@
 	$(qexec)echo 'Libs: -L$${libdir} -lvpx' >> $@
 	$(qexec)echo 'Libs.private: -lm -pthread' >> $@
 	$(qexec)echo 'Cflags: -I$${includedir}' >> $@
-INSTALL-LIBS-yes += $(LIBSUBDIR)/pkgconfig/vpx.pc
-INSTALL_MAPS += $(LIBSUBDIR)/pkgconfig/%.pc %.pc
+INSTALL-LIBS-yes += libdata/pkgconfig/vpx.pc
+INSTALL_MAPS += libdata/pkgconfig/%.pc %.pc
 CLEAN-OBJS += vpx.pc
 endif
 
