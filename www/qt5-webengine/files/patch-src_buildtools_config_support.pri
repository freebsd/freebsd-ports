* Add support for FreeBSD

--- src/buildtools/config/support.pri.orig	2024-03-27 11:26:34 UTC
+++ src/buildtools/config/support.pri
@@ -5,7 +5,7 @@ defineReplace(qtwebengine_checkWebEngineCoreError) {
 
 # this should match webengine-core-support
 defineReplace(qtwebengine_checkWebEngineCoreError) {
-    !linux:!win32:!macos {
+    !linux:!win32:!macos:!unix {
         qtwebengine_skipBuild("QtWebEngine can be built only on Linux, Windows or macOS.")
         return(false)
     }
@@ -24,14 +24,14 @@ defineReplace(qtwebengine_checkWebEngineCoreError) {
     !qtwebengine_checkForPython(QtWebEngine):return(false)
     !qtwebengine_checkForNodejs(QtWebEngine):return(false)
     !qtwebengine_checkForSanitizer(QtWebEngine):return(false)
-    linux:!qtwebengine_checkForPkgCfg(QtWebEngine):return(false)
-    linux:!qtwebengine_checkForHostPkgCfg(QtWebEngine):return(false)
+    unix:!qtwebengine_checkForPkgCfg(QtWebEngine):return(false)
+    unix:!qtwebengine_checkForHostPkgCfg(QtWebEngine):return(false)
     linux:!qtwebengine_checkForGlibc(QtWebEngine):return(false)
-    linux:!qtwebengine_checkForKhronos(QtWebEngine):return(false)
-    linux:!qtwebengine_checkForPackage(QtWebEngine,nss):return(false)
-    linux:!qtwebengine_checkForPackage(QtWebEngine,dbus):return(false)
-    linux:!qtwebengine_checkForPackage(QtWebEngine,fontconfig):return(false)
-    linux:!qtwebengine_checkForQpaXcb(QtWebEngine):return(false)
+    unix:!qtwebengine_checkForKhronos(QtWebEngine):return(false)
+    unix:!qtwebengine_checkForPackage(QtWebEngine,nss):return(false)
+    unix:!qtwebengine_checkForPackage(QtWebEngine,dbus):return(false)
+    unix:!qtwebengine_checkForPackage(QtWebEngine,fontconfig):return(false)
+    unix:!qtwebengine_checkForQpaXcb(QtWebEngine):return(false)
     win32:!qtwebengine_checkForCompiler64(QtWebEngine):return(false)
     win32:!qtwebengine_checkForWinVersion(QtWebEngine):return(false)
     return(true)
@@ -39,7 +39,7 @@ defineReplace(qtwebengine_checkPdfError) {
 
 # this shuold match webengine-qtpdf-support
 defineReplace(qtwebengine_checkPdfError) {
-    !linux:!win32:!macos:!ios {
+    !linux:!win32:!macos:!ios:!unix {
         qtwebengine_skipBuild("QtPdf can be built only on Linux, Windows, macOS or iOS.")
         return(false)
     }
@@ -53,8 +53,8 @@ defineReplace(qtwebengine_checkPdfError) {
     !qtwebengine_checkForFlex(QtPdf):return(false)
     !qtwebengine_checkForPython(QtPdf):return(false)
     !qtwebengine_checkForSanitizer(QtPdf):return(false)
-    linux:!qtwebengine_checkForPkgCfg(QtPdf):return(false)
-    linux:!qtwebengine_checkForHostPkgCfg(QtPdf):return(false)
+    unix:!qtwebengine_checkForPkgCfg(QtPdf):return(false)
+    unix:!qtwebengine_checkForHostPkgCfg(QtPdf):return(false)
     win32:!qtwebengine_checkForWinVersion(QtPdf):return(false)
     return(true)
 }
