--- ./libs/libmyth/libmyth.pro.orig	2008-03-04 12:08:41.000000000 -0500
+++ ./libs/libmyth/libmyth.pro	2009-04-22 21:04:16.000000000 -0400
@@ -43,14 +43,14 @@
 SOURCES += volumebase.cpp volumecontrol.cpp virtualkeyboard.cpp xmlparse.cpp
 SOURCES += mythhdd.cpp mythcdrom.cpp storagegroup.cpp dbutil.cpp
 
-INCLUDEPATH += ../libmythsamplerate ../libmythsoundtouch ../libmythfreesurround
-INCLUDEPATH += ../libavcodec ../libavutil
-INCLUDEPATH += ../.. ../ ./
-DEPENDPATH += ../libmythsamplerate ../libmythsoundtouch
-DEPENDPATH += ../libmythfreesurround
-DEPENDPATH += ../libavcodec ../libavutil
-DEPENDPATH += ../ ../libmythui
-DEPENDPATH += ../libmythupnp
+INCLUDEPATH = ../libmythsamplerate ../libmythsoundtouch ../libmythfreesurround $${INCLUDEPATH}
+INCLUDEPATH = ../libavcodec ../libavutil $${INCLUDEPATH}
+INCLUDEPATH = ../.. ../ ./ $${INCLUDEPATH}
+DEPENDPATH = ../libmythsamplerate ../libmythsoundtouch $${DEPENDPATH}
+DEPENDPATH = ../libmythfreesurround $${DEPENDPATH}
+DEPENDPATH = ../libavcodec ../libavutil $${DEPENDPATH}
+DEPENDPATH = ../ ../libmythui $${DEPENDPATH}
+DEPENDPATH = ../libmythupnp $${DEPENDPATH}
 
 
 LIBS += -L../libmythsamplerate   -lmythsamplerate-$${LIBVERSION}
