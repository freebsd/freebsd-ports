--- build_tools/build.pro.orig	2021-12-12 19:27:25 UTC
+++ build_tools/build.pro
@@ -8,6 +8,10 @@ include($$PWD/common.pri)
 
 CONFIG += ordered
 
+core_freebsd {
+       CONFIG += no_desktop_apps
+       CONFIG += no_use_htmlfileinternal
+}
 core_windows {
 	CONFIG += core_and_multimedia
 }
