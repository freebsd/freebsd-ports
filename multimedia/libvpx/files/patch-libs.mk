--- libs.mk.orig	2017-01-12 20:27:27 UTC
+++ libs.mk
@@ -117,8 +117,8 @@ endif
 $(BUILD_PFX)third_party/googletest/%.cc.o: CXXFLAGS += -Wno-missing-field-initializers
 # Suppress -Wextra warnings in first party code pending investigation.
 # https://bugs.chromium.org/p/webm/issues/detail?id=1069
-$(BUILD_PFX)vp8/encoder/onyx_if.c.o: CFLAGS += -Wno-unknown-warning-option -Wno-clobbered
-$(BUILD_PFX)vp8/decoder/onyxd_if.c.o: CFLAGS += -Wno-unknown-warning-option -Wno-clobbered
+$(BUILD_PFX)vp8/encoder/onyx_if.c.o: CFLAGS += -Wno-extra
+$(BUILD_PFX)vp8/decoder/onyxd_if.c.o: CFLAGS += -Wno-extra
 
 ifeq ($(CONFIG_MSVS),yes)
 CODEC_LIB=$(if $(CONFIG_STATIC_MSVCRT),vpxmt,vpxmd)
@@ -339,8 +339,8 @@ else
 	$(qexec)echo 'Libs.private: -lm' >> $@
 endif
 	$(qexec)echo 'Cflags: -I$${includedir}' >> $@
-INSTALL-LIBS-yes += $(LIBSUBDIR)/pkgconfig/vpx.pc
-INSTALL_MAPS += $(LIBSUBDIR)/pkgconfig/%.pc %.pc
+INSTALL-LIBS-yes += libdata/pkgconfig/vpx.pc
+INSTALL_MAPS += libdata/pkgconfig/%.pc %.pc
 CLEAN-OBJS += vpx.pc
 endif
 
