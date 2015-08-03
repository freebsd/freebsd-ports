--- src/src.pro.orig	2013-06-16 09:57:51 UTC
+++ src/src.pro
@@ -12,6 +12,8 @@ QT += xml
 system(pkg-config --exists libavcodec) {
 	message(Building with external FFMPEG)
 	PKGCONFIG += libavformat libavcodec libavutil
+	QMAKE_CXXFLAGS += -DHAVE_LIB_A52
+	LIBS += -la52
 
 	system(pkg-config --exists libswscale) {
 		message(Building with libswscale support)
@@ -70,7 +72,7 @@ verinfo.commands = ../setversion.sh $$SO
 
 QMAKE_EXTRA_TARGETS += verinfo
 
-qtPrepareTool(LRELEASE, lrelease)
+qtPrepareTool(LRELEASE, lrelease-qt4)
 
 l10n.commands = $$LRELEASE ${QMAKE_FILE_IN} -qm ${QMAKE_FILE_OUT}
 l10n.input = TRANSLATIONS
