--- libng/contrib-plugins/Subdir.mk.orig	Thu Feb 13 15:15:28 2003
+++ libng/contrib-plugins/Subdir.mk	Thu Feb 13 15:15:34 2003
@@ -18,7 +18,7 @@
 
 # linear-blend has mmx support ...
 ifeq ($(USE_MMX),yes)
-libng/contrib-plugins/linear-blend.so : CFLAGS += -DMMX=1
+#libng/contrib-plugins/linear-blend.so : CFLAGS += -DMMX=1
 endif
 
 # global targets
