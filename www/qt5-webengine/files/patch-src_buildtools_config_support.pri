--- src/buildtools/config/support.pri.orig	2020-03-16 14:04:24 UTC
+++ src/buildtools/config/support.pri
@@ -64,6 +64,7 @@ defineReplace(qtwebengine_checkError) {
     linux:!qtwebengine_checkErrorForLinux():return(false)
     win32:!qtwebengine_checkErrorForWindows():return(false)
     macos:!qtwebengine_checkErrorForMacOS():return(false)
+    unix:!qtwebengine_checkErrorForLinux():return(false)
 
     sanitizer: !qtConfig(webengine-sanitizer) {
         qtwebengine_skipBuild("Chosen sanitizer configuration is not supported for QtWebEngine. Check config.log for details or use -feature-webengine-sanitizer to force build with the chosen sanitizer configuration.")
