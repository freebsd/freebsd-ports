* Rename Python2 functions to generic Python ones [1]
* Add support for FreeBSD

[1] Obtained from:

https://gitlab.archlinux.org/archlinux/packaging/packages/qt5-webengine/-/raw/main/qt5-webengine-python3.patch?ref_type=heads

--- src/buildtools/config/support.pri.orig	2023-07-20 09:52:10 UTC
+++ src/buildtools/config/support.pri
@@ -5,7 +5,7 @@ defineReplace(qtwebengine_checkWebEngineCoreError) {
 
 # this should match webengine-core-support
 defineReplace(qtwebengine_checkWebEngineCoreError) {
-    !linux:!win32:!macos {
+    !linux:!win32:!macos:!unix {
         qtwebengine_skipBuild("QtWebEngine can be built only on Linux, Windows or macOS.")
         return(false)
     }
@@ -21,17 +21,17 @@ defineReplace(qtwebengine_checkWebEngineCoreError) {
     !qtwebengine_checkForGperf(QtWebEngine):return(false)
     !qtwebengine_checkForBison(QtWebEngine):return(false)
     !qtwebengine_checkForFlex(QtWebEngine):return(false)
-    !qtwebengine_checkForPython2(QtWebEngine):return(false)
+    !qtwebengine_checkForPython(QtWebEngine):return(false)
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
@@ -51,10 +51,12 @@ defineReplace(qtwebengine_checkPdfError) {
     !qtwebengine_checkForGperf(QtPdf):return(false)
     !qtwebengine_checkForBison(QtPdf):return(false)
     !qtwebengine_checkForFlex(QtPdf):return(false)
-    !qtwebengine_checkForPython2(QtPdf):return(false)
+    !qtwebengine_checkForPython(QtPdf):return(false)
     !qtwebengine_checkForSanitizer(QtPdf):return(false)
     linux:!qtwebengine_checkForPkgCfg(QtPdf):return(false)
     linux:!qtwebengine_checkForHostPkgCfg(QtPdf):return(false)
+    unix:!qtwebengine_checkForPkgCfg(QtPdf):return(false)
+    unix:!qtwebengine_checkForHostPkgCfg(QtPdf):return(false)
     win32:!qtwebengine_checkForWinVersion(QtPdf):return(false)
     return(true)
 }
@@ -143,10 +145,10 @@ defineTest(qtwebengine_checkForFlex) {
     return(true)
 }
 
-defineTest(qtwebengine_checkForPython2) {
+defineTest(qtwebengine_checkForPython) {
     module = $$1
-    !qtConfig(webengine-python2) {
-        qtwebengine_skipBuild("Python version 2 (2.7.5 or later) is required to build $${module}.")
+    !qtConfig(webengine-python) {
+        qtwebengine_skipBuild("Python is required to build $${module}.")
         return(false)
     }
     return(true)
