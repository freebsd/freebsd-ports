--- configure.pri.orig	2020-11-07 01:22:36 UTC
+++ configure.pri
@@ -123,6 +123,9 @@ defineTest(qtConfTest_detectPlatform) {
     macos:qtwebengine_isMacOsPlatformSupported() {
         $${1}.platform = "macos"
     }
+    unix:qtwebengine_isLinuxPlatformSupported() {
+        $${1}.platform = "linux"
+    }
     ios:qtwebengine_isMacOsPlatformSupported() {
         $${1}.platform = "ios"
     }
