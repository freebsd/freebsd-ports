--- debug/Subdir.mk.orig	Mon Jun 24 02:12:21 2002
+++ debug/Subdir.mk	Mon Jun 24 02:12:46 2002
@@ -22,8 +22,8 @@
 
 debug/xvideo: debug/xvideo.o
 
-debug/gl     : LDLIBS  := $(THREADLIB) $(MOTIF_LIBS) -lGLU -lGL -ljpeg -lm
-debug/hwscan : LDLIBS  := $(ALSA_LIBS) -ljpeg
+debug/gl     : LDLIBS  := $(THREADLIB) $(MOTIF_LIBS) -L%%LOCALBASE%%/lib -lGLU -lGL -ljpeg -lm
+debug/hwscan : LDLIBS  := $(ALSA_LIBS) -L%%LOCALBASE%%/lib -ljpeg
 debug/xvideo : LDLIBS  := $(ATHENA_LIBS)
 
 debug/gl     : LDFLAGS := $(DLFLAGS)
