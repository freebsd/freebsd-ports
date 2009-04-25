--- libs/libmythtv/libmythtv.pro.orig	2009-04-22 21:32:52.000000000 -0400
+++ libs/libmythtv/libmythtv.pro	2009-04-22 21:33:01.000000000 -0400
@@ -49,6 +49,7 @@
 
 
 DEFINES += _LARGEFILE_SOURCE
+QMAKE_CXXFLAGS = -I../libmyth -I../libavcodec -I../libavutil -I../libmythmpeg2 $${QMAKE_CXXFLAGS}
 QMAKE_CXXFLAGS += $${FREETYPE_CFLAGS}
 QMAKE_LFLAGS_SHLIB += $${FREETYPE_LIBS}
 
@@ -312,6 +313,8 @@
     using_opengl_video:HEADERS += openglvideo.h
     using_opengl_video:SOURCES += openglvideo.cpp
 
+    using_glx_proc_addr_arb:DEFINES += USING_GLX_PROC_ADDR_ARB
+
     # Misc. frontend
     HEADERS += guidegrid.h              infostructs.h
     HEADERS += progfind.h               ttfont.h
