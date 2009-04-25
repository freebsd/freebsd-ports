--- ./libs/libmythtv/libmythtv.pro.orig	2008-02-18 17:59:32.000000000 -0500
+++ ./libs/libmythtv/libmythtv.pro	2009-04-22 21:04:16.000000000 -0400
@@ -49,6 +49,7 @@
 
 
 DEFINES += _LARGEFILE_SOURCE
+QMAKE_CXXFLAGS = -I../libmyth -I../libavcodec -I../libavutil -I../libmythmpeg2 $${QMAKE_CXXFLAGS}
 QMAKE_CXXFLAGS += $${FREETYPE_CFLAGS}
 QMAKE_LFLAGS_SHLIB += $${FREETYPE_LIBS}
 
