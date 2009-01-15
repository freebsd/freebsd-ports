--- libs/libmythtv/libmythtv.pro.orig	2008-02-18 23:59:32.000000000 +0100
+++ libs/libmythtv/libmythtv.pro	2008-09-22 11:56:52.000000000 +0200
@@ -49,6 +49,7 @@
 
 
 DEFINES += _LARGEFILE_SOURCE
+QMAKE_CXXFLAGS = -I../libmyth -I../libavcodec -I../libavutil -I../libmythmpeg2 $${QMAKE_CXXFLAGS}
 QMAKE_CXXFLAGS += $${FREETYPE_CFLAGS}
 QMAKE_LFLAGS_SHLIB += $${FREETYPE_LIBS}
 
