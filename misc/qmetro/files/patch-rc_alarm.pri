--- rc/alarm.pri.orig	2013-04-02 11:27:07.017366450 +0000
+++ rc/alarm.pri	2013-04-02 11:36:52.435366521 +0000
@@ -8,13 +8,6 @@ QT += multimedia
 CONFIG += mobility
 MOBILITY = multimedia
 
-unix:!macx:!maemo5:!contains(MEEGO_EDITION,harmattan):!symbian {
-QT -= multimedia
-INCLUDEPATH += /usr/include/QtMultimediaKit \
-               /usr/include/QtMobility
-#LIBS += -lQtMultimediaKit
-}
-
 
 DEFINES += QMETRO_HAVE_ALARM=1
 
