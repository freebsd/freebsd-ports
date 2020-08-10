--- minitube.pro.orig	2020-08-10 17:56:42 UTC
+++ minitube.pro
@@ -43,6 +43,8 @@ include(lib/media/media.pri)
 include(src/qtsingleapplication/qtsingleapplication.pri)
 include(src/invidious/invidious.pri)
 
+INCLUDEPATH += $$PWD/src
+
 HEADERS += src/video.h \
     src/messagebar.h \
     src/spacer.h \
