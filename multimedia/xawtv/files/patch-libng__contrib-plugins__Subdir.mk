--- libng/contrib-plugins/Subdir.mk.orig	2020-05-15 23:32:25 UTC
+++ libng/contrib-plugins/Subdir.mk
@@ -18,7 +18,7 @@ libng/contrib-plugins/snd-alsa.so : LDLIBS := $(ALSA_L
 
 # linear-blend has mmx support ...
 ifeq ($(USE_MMX),yes)
-libng/contrib-plugins/linear-blend.so : CFLAGS += -DMMX=1
+#libng/contrib-plugins/linear-blend.so : CFLAGS += -DMMX=1
 endif
 
 # global targets
