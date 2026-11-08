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
@@ -281,11 +281,13 @@ QMAKE_CXXFLAGS_RELEASE += -O3 \
                           -Werror \
                           -Wextra \
                           -Wformat=2 \
-                          -Wold-style-cast \
+                          -Wno-old-style-cast \
                           -Woverloaded-virtual \
                           -Wpointer-arith \
                           -Wstack-protector \
                           -Wstrict-overflow=5 \
+                          -Wno-c++20-attribute-extensions \
+                          -Wno-c++26-extensions \
                           -Wundef \
                           -Wzero-as-null-pointer-constant \
                           -fPIE \
@@ -306,12 +308,13 @@ QMAKE_CXXFLAGS_RELEASE += -O3 \
                           -Wcast-qual \
                           -Wextra \
                           -Wformat=2 \
-                          -Wno-c++20-attribute-extensions \
-                          -Wold-style-cast \
+                          -Wno-old-style-cast \
                           -Woverloaded-virtual \
                           -Wpointer-arith \
                           -Wstack-protector \
                           -Wstrict-overflow=5 \
+                          -Wno-c++20-attribute-extensions \
+                          -Wno-c++26-extensions \
                           -fPIE \
                           -fstack-protector-all \
                           -funroll-loops \
@@ -361,7 +364,7 @@ QMAKE_CXXFLAGS_RELEASE += -O3 \
                           -Wformat=2 \
                           -Wlogical-op \
                           -Wno-deprecated-copy \
-                          -Wold-style-cast \
+                          -Wno-old-style-cast \
                           -Woverloaded-virtual \
                           -Wpointer-arith \
                           -Wstack-protector \
@@ -370,6 +373,8 @@ QMAKE_CXXFLAGS_RELEASE += -O3 \
                           -Wtrampolines \
                           -Wundef \
                           -Wzero-as-null-pointer-constant \
+                          -Wno-c++20-attribute-extensions \
+                          -Wno-c++26-extensions \
                           -fstack-clash-protection \
                           -fstack-protector-all \
                           -funroll-loops \
