--- configure.pri.orig	2019-12-03 07:18:02 UTC
+++ configure.pri
@@ -114,7 +114,7 @@ defineTest(qtwebengine_platformError) {
 defineTest(qtConfTest_detectPlatform) {
     QT_FOR_CONFIG += gui-private
 
-    !linux:!win32:!macos {
+    !linux:!win32:!macos:!unix: {
         qtwebengine_platformError("Unknown platform. Qt WebEngine only supports Linux, Windows, and macOS.")
     } else {
         linux:qtwebengine_isLinuxPlatformSupported() {
@@ -126,6 +126,9 @@ defineTest(qtConfTest_detectPlatform) {
         macos:qtwebengine_isMacOsPlatformSupported() {
             $${1}.platform = "macos"
         }
+        unix:qtwebengine_isLinuxPlatformSupported() {
+            $${1}.platform = "linux"
+        }
     }
 
     !isEmpty(platformError) {
