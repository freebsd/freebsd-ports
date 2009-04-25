--- ./programs/mythtranscode/mythtranscode.pro.orig	2007-02-24 12:44:00.000000000 -0500
+++ ./programs/mythtranscode/mythtranscode.pro	2009-04-22 21:05:21.000000000 -0400
@@ -20,3 +20,7 @@
 INCLUDEPATH += replex
 INCLUDEPATH += ../../libs/libavcodec ../../libs/libavformat \
                ../../libs/libavutil  ../../libs/libmythmpeg2
+
+QMAKE_CXXFLAGS = -I../../libs/libavcodec -I../../libs/libavformat \
+                 -I../../libs/libavutil -I../../libs/libmythmpeg2 \
+                 $${QMAKE_CXXFLAGS}
