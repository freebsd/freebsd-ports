--- configure.pri.orig	2020-04-08 09:41:36 UTC
+++ configure.pri
@@ -114,7 +114,7 @@ defineTest(qtwebengine_platformError) {
 defineTest(qtConfTest_detectPlatform) {
     QT_FOR_CONFIG += gui-private
 
-    !linux:!win32:!macos:!ios {
+    !linux:!win32:!macos:!ios:!unix: {
         qtwebengine_platformError("Unknown platform. Qt WebEngine only supports Linux, Windows, and macOS.")
     } else {
         linux:qtwebengine_isLinuxPlatformSupported() {
@@ -125,6 +125,9 @@ defineTest(qtConfTest_detectPlatform) {
         }
         macos:qtwebengine_isMacOsPlatformSupported() {
             $${1}.platform = "macos"
+        }
+        unix:qtwebengine_isLinuxPlatformSupported() {
+            $${1}.platform = "linux"
         }
         ios:qtwebengine_isMacOsPlatformSupported() {
             $${1}.platform = "ios"
