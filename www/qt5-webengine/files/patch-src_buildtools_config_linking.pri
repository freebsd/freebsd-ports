--- src/buildtools/config/linking.pri.orig	2020-11-07 01:22:36 UTC
+++ src/buildtools/config/linking.pri
@@ -1,6 +1,9 @@
 include($$QTWEBENGINE_OUT_ROOT/src/buildtools/qtbuildtools-config.pri)
 QT_FOR_CONFIG += buildtools-private
 
+# Do not pass --no-undefined to the linker because of environ(7) usage.
+freebsd: QMAKE_LFLAGS_NOUNDEF =
+
 linking_pri = $$OUT_PWD/$$getConfigDir()/$${TARGET}.pri
 
 !include($$linking_pri) {
@@ -34,7 +37,7 @@ if(macos|ios) {
     }
 }
 
-linux {
+unix {
     !static {
         QMAKE_LFLAGS += @$${RSP_OBJECT_FILE}
         QMAKE_LFLAGS += -Wl,--start-group @$${RSP_ARCHIVE_FILE} -Wl,--end-group
@@ -60,7 +63,7 @@ LIBS_PRIVATE += $$NINJA_LIB_DIRS $$NINJA_LIBS
 
 unix:qtConfig(webengine-noexecstack): \
     QMAKE_LFLAGS += -Wl,-z,noexecstack
-linux {
+unix {
     # add chromium flags
     for(flag, NINJA_LFLAGS) {
         # filter out some flags
