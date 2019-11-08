--- src/core/core_module.pro.orig	2019-10-23 10:30:33 UTC
+++ src/core/core_module.pro
@@ -4,6 +4,9 @@ include(core_common.pri)
 # Needed to set a CFBundleIdentifier
 QMAKE_INFO_PLIST = Info_mac.plist
 
+# Do not pass --no-undefined to the linker because of environ(7) usage.
+freebsd: QMAKE_LFLAGS_NOUNDEF =
+
 linking_pri = $$OUT_PWD/$$getConfigDir()/$${TARGET}.pri
 
 !include($$linking_pri) {
@@ -30,10 +33,10 @@ RSP_ARCHIVE_FILE = $$OUT_PWD/$$getConfigDir()/$${TARGE
 for(archive, NINJA_ARCHIVES): RSP_A_CONTENT += $$archive
 write_file($$RSP_ARCHIVE_FILE, RSP_A_CONTENT)
 macos:LIBS_PRIVATE += -Wl,-filelist,$$shell_quote($$RSP_OBJECT_FILE)
-linux:QMAKE_LFLAGS += @$${RSP_OBJECT_FILE}
+unix:QMAKE_LFLAGS += @$${RSP_OBJECT_FILE}
 # QTBUG-58710 add main rsp file on windows
 win32:QMAKE_LFLAGS += @$${RSP_OBJECT_FILE}
-linux:QMAKE_LFLAGS += -Wl,--start-group @$${RSP_ARCHIVE_FILE} -Wl,--end-group
+unix:QMAKE_LFLAGS += -Wl,--start-group @$${RSP_ARCHIVE_FILE} -Wl,--end-group
 else: LIBS_PRIVATE += $$NINJA_ARCHIVES
 LIBS_PRIVATE += $$NINJA_LIB_DIRS $$NINJA_LIBS
 # GN's LFLAGS doesn't always work across all the Linux configurations we support.
@@ -41,7 +44,7 @@ LIBS_PRIVATE += $$NINJA_LIB_DIRS $$NINJA_LIBS
 
 unix:qtConfig(webengine-noexecstack): \
     QMAKE_LFLAGS += -Wl,-z,noexecstack
-linux {
+unix {
     # add chromium flags
     for(flag, NINJA_LFLAGS) {
         # filter out some flags
@@ -91,7 +94,7 @@ win32 {
 # and doesn't let Chromium get access to libc symbols through dlsym.
 CONFIG -= bsymbolic_functions
 
-linux:qtConfig(separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
+unix:qtConfig(separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
 
 REPACK_DIR = $$OUT_PWD/$$getConfigDir()
 
