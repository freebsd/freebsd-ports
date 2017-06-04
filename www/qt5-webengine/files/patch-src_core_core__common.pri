Do not pass --no-undefined to the linker, Chromium uses `environ'.
--- src/core/core_common.pri.orig	2017-04-18 20:27:53 UTC
+++ src/core/core_common.pri
@@ -5,6 +5,9 @@ TARGET = QtWebEngineCore
 QT += qml quick webchannel
 QT_PRIVATE += quick-private gui-private core-private webenginecoreheaders-private
 
+# The code uses environ, so we cannot pass --no-undefined to the linker.
+freebsd: QMAKE_LFLAGS_NOUNDEF =
+
 # Make QtCreator happy.
 CHROMIUM_SRC_DIR = $$QTWEBENGINE_ROOT/$$getChromiumSrcDir()
 INCLUDEPATH += $$CHROMIUM_SRC_DIR
