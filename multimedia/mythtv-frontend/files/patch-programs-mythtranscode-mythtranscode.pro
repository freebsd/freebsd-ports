--- programs/mythtranscode/mythtranscode.pro.orig	2008-09-23 11:10:01.000000000 +0200
+++ programs/mythtranscode/mythtranscode.pro	2008-09-23 11:10:42.000000000 +0200
@@ -20,3 +20,7 @@
 INCLUDEPATH += replex
 INCLUDEPATH += ../../libs/libavcodec ../../libs/libavformat \
                ../../libs/libavutil  ../../libs/libmythmpeg2
+
+QMAKE_CXXFLAGS = -I../../libs/libavcodec -I../../libs/libavformat \
+                 -I../../libs/libavutil -I../../libs/libmythmpeg2 \
+                 $${QMAKE_CXXFLAGS}
