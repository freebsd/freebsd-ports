--- dooble.pro.orig	2026-08-21 03:55:17 UTC
+++ dooble.pro
@@ -10,7 +10,7 @@ freebsd-* {
 } else {
 versionAtLeast(QT_VERSION, 6.0.0) {
 freebsd-* {
-CONVERT_DICT = "/usr/local/libexec/qt6/qwebengine_convert_dict"
+CONVERT_DICT = "%%LOCALBASE%%/libexec/qt6/qwebengine_convert_dict"
 } else:win32 {
 qtPrepareTool(CONVERT_DICT, qwebengine_convert_dict)
 } else {
@@ -208,7 +208,7 @@ freebsd-* {
 build_deb.bash =
 
 freebsd-* {
-exists(/usr/local/include/gpgme.h) {
+exists(%%LOCALBASE%%/include/gpgme.h) {
 DEFINES += DOOBLE_PEEKABOO
 LIBS += -lgpgme
 message("Discovered gpgme.h. Peekaboo activated!")
@@ -281,7 +281,7 @@ QMAKE_CXXFLAGS_RELEASE += -O3 \
                           -Werror \
                           -Wextra \
                           -Wformat=2 \
-                          -Wold-style-cast \
+                          -Wno-old-style-cast \
                           -Woverloaded-virtual \
                           -Wpointer-arith \
                           -Wstack-protector \
