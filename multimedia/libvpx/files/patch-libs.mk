--- libs.mk.orig	2024-01-09 21:12:22 UTC
+++ libs.mk
@@ -408,8 +408,8 @@ endif
 	$(qexec)echo 'Libs.private: -lm' >> $@
 endif
 	$(qexec)echo 'Cflags: -I$${includedir}' >> $@
-INSTALL-LIBS-yes += $(LIBSUBDIR)/pkgconfig/vpx.pc
-INSTALL_MAPS += $(LIBSUBDIR)/pkgconfig/%.pc %.pc
+INSTALL-LIBS-yes += libdata/pkgconfig/vpx.pc
+INSTALL_MAPS += libdata/pkgconfig/%.pc %.pc
 CLEAN-OBJS += vpx.pc
 
 ifeq ($(CONFIG_ENCODERS),yes)
