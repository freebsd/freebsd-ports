--- src/buildtools/config/support.pri.orig	2020-01-09 09:16:12 UTC
+++ src/buildtools/config/support.pri
@@ -68,6 +68,7 @@ defineReplace(qtwebengine_checkError) {
 
     linux:!qtwebengine_checkErrorForLinux():return(false)
     win:!qtwebengine_checkErrorForWindows():return(false)
+    unix:!qtwebengine_checkErrorForLinux():return(false)
 
     sanitizer: !qtConfig(webengine-sanitizer) {
         qtwebengine_skipBuild("Chosen sanitizer configuration is not supported for QtWebEngine. Check config.log for details or use -feature-webengine-sanitizer to force build with the chosen sanitizer configuration.")
