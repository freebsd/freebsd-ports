* Add support for FreeBSD

--- configure.pri.orig	2024-03-27 11:26:34 UTC
+++ configure.pri
@@ -136,6 +136,9 @@ defineTest(qtConfTest_detectPlatform) {
     macos:qtwebengine_isMacOsPlatformSupported() {
         $${1}.platform = "macos"
     }
+    unix:qtwebengine_isLinuxPlatformSupported() {
+        $${1}.platform = "linux"
+    }
     ios:qtwebengine_isMacOsPlatformSupported() {
         $${1}.platform = "ios"
     }
