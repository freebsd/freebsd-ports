--- build_tools/build.pro.orig	2021-12-12 19:27:25 UTC
+++ build_tools/build.pro
--- build_tools/build.pro.orig	2022-02-28 14:20:10.000000000 +0100
+++ build_tools/build.pro	2022-03-03 10:11:49.033261000 +0100
@@ -8,6 +8,9 @@ include($$PWD/common.pri)
 
 CONFIG += ordered
 
+core_freebsd {
+       CONFIG += no_desktop_apps
+}
 core_windows {
 	desktop:CONFIG += core_and_multimedia
 }
