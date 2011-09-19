
$FreeBSD$

--- libs.mk.orig
+++ libs.mk
@@ -242,8 +242,8 @@
 	$(qexec)echo 'Conflicts:' >> $@
 	$(qexec)echo 'Libs: -L$${libdir} -lvpx' >> $@
 	$(qexec)echo 'Cflags: -I$${includedir}' >> $@
-INSTALL-LIBS-yes += $(LIBSUBDIR)/pkgconfig/vpx.pc
-INSTALL_MAPS += $(LIBSUBDIR)/pkgconfig/%.pc %.pc
+INSTALL-LIBS-yes += libdata/pkgconfig/vpx.pc
+INSTALL_MAPS += libdata/pkgconfig/%.pc %.pc
 CLEAN-OBJS += vpx.pc
 endif
 
