--- console/Subdir.mk.orig	Sat Jun 22 17:04:53 2002
+++ console/Subdir.mk	Sat Jun 22 17:05:30 2002
@@ -65,11 +65,11 @@
 # libraries to link
 console/fbtv     : LDLIBS  := \
 	$(THREAD_LIBS) $(CURSES_LIBS) $(LIRC_LIBS) $(ALSA_LIBS) \
-	$(FS_LIBS) -ljpeg -lm
-console/ttv      : LDLIBS  := $(THREAD_LIBS) $(AA_LIBS) -ljpeg -lm
-console/scantv   : LDLIBS  := $(THREAD_LIBS) $(VBI_LIBS) -ljpeg
-console/streamer : LDLIBS  := $(THREAD_LIBS) -ljpeg -lm
-console/webcam   : LDLIBS  := $(THREAD_LIBS) -ljpeg
+	$(FS_LIBS) -L%%LOCALBASE%%/lib -ljpeg -lm
+console/ttv      : LDLIBS  := $(THREAD_LIBS) $(AA_LIBS) -L%%LOCALBASE%%/lib -ljpeg -lm
+console/scantv   : LDLIBS  := $(THREAD_LIBS) $(VBI_LIBS) -L%%LOCALBASE%%/lib -ljpeg
+console/streamer : LDLIBS  := $(THREAD_LIBS) -L%%LOCALBASE%%/lib -ljpeg -lm
+console/webcam   : LDLIBS  := $(THREAD_LIBS) -L%%LOCALBASE%%/lib -ljpeg
 console/radio    : LDLIBS  := $(CURSES_LIBS)
 console/record   : LDLIBS  := $(CURSES_LIBS)
 console/v4l-conf : LDLIBS  := $(ATHENA_LIBS)
