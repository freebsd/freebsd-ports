--- build_tools/build.pro.orig	2021-12-12 19:27:25 UTC
+++ build_tools/build.pro
@@ -18,6 +18,9 @@ mobile:CONFIG += core_libraries
 !core_libraries:CONFIG += no_use_common_binary
 !core_libraries:CONFIG += no_tests
 
+core_freebsd {
+       CONFIG += no_desktop_apps
+}
 core_windows {
     desktop:CONFIG += core_and_multimedia
 }
@@ -96,8 +99,6 @@ core_libraries {
     addSubProject(docbuilder,     $$CORE_ROOT_DIR/DesktopEditor/doctrenderer/app_builder/docbuilder.pro,\
                                       kernel unicodeconverter graphics doctrenderer)
     addSubProject(pluginsmanager, $$CORE_ROOT_DIR/DesktopEditor/pluginsmanager/pluginsmanager.pro,\
-                                      kernel)
-    addSubProject(vboxtester,     $$CORE_ROOT_DIR/DesktopEditor/vboxtester/vboxtester.pro,\
                                       kernel)
 }
 
