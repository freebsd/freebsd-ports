--- src/tools/qwebengine_convert_dict/qwebengine_convert_dict.pro.orig	2018-11-27 04:10:38 UTC
+++ src/tools/qwebengine_convert_dict/qwebengine_convert_dict.pro
@@ -12,7 +12,7 @@ isEmpty(NINJA_LFLAGS): error("Missing linker flags fro
 isEmpty(NINJA_ARCHIVES): error("Missing archive files from QtWebEngineCore linking pri")
 isEmpty(NINJA_LIBS): error("Missing library files from QtWebEngineCore linking pri")
 OBJECTS = $$eval($$list($$NINJA_OBJECTS))
-linux {
+unix {
     LIBS_PRIVATE = -Wl,--start-group $$NINJA_ARCHIVES -Wl,--end-group
 } else {
     LIBS_PRIVATE = $$NINJA_ARCHIVES
