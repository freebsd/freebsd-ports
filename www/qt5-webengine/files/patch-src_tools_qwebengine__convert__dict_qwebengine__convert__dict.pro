Extend another Linux check to FreeBSD, so that the right parameters are passed
to the linker.

--- src/tools/qwebengine_convert_dict/qwebengine_convert_dict.pro
+++ src/tools/qwebengine_convert_dict/qwebengine_convert_dict.pro
@@ -12,7 +12,7 @@ isEmpty(NINJA_LFLAGS): error("Missing linker flags from QtWebEngineCore linking
 isEmpty(NINJA_ARCHIVES): error("Missing archive files from QtWebEngineCore linking pri")
 isEmpty(NINJA_LIBS): error("Missing library files from QtWebEngineCore linking pri")
 OBJECTS = $$eval($$list($$NINJA_OBJECTS))
-linux {
+unix {
     LIBS_PRIVATE = -Wl,--start-group $$NINJA_ARCHIVES -Wl,--end-group
 } else {
     LIBS_PRIVATE = $$NINJA_ARCHIVES
