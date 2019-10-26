* Do not pass --no-undefined and -z,defs to the linker because of environ(7).
* Extend some Linux-only compiler arguments to FreeBSD.
* Generate split out debug files on FreeBSD too.

--- src/core/core_module.pro.orig	2019-05-24 09:01:39 UTC
+++ src/core/core_module.pro
@@ -4,6 +4,9 @@ include(core_common.pri)
 # Needed to set a CFBundleIdentifier
 QMAKE_INFO_PLIST = Info_mac.plist
 
+# Do not pass --no-undefined to the linker because of environ(7) usage.
+freebsd: QMAKE_LFLAGS_NOUNDEF =
+
 linking_pri = $$OUT_PWD/$$getConfigDir()/$${TARGET}.pri
 
 !include($$linking_pri) {
@@ -30,21 +33,21 @@ RSP_ARCHIVE_FILE = $$OUT_PWD/$$getConfigDir()/$${TARGE
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
 # The Windows and macOS ones from GN does provide a few useful flags however
 
-linux {
+unix {
     QMAKE_LFLAGS += -Wl,--gc-sections -Wl,-O1 -Wl,-z,now
     # Embedded address sanitizer symbols are undefined and are picked up by the dynamic link loader
     # at runtime. Thus we do not to pass the linker flag below, because the linker would complain
     # about the undefined sanitizer symbols.
-    !sanitizer: QMAKE_LFLAGS += -Wl,-z,defs
+    #!sanitizer: QMAKE_LFLAGS += -Wl,-z,defs
 } else {
     QMAKE_LFLAGS += $$NINJA_LFLAGS
 }
@@ -85,7 +88,7 @@ win32 {
 # and doesn't let Chromium get access to libc symbols through dlsym.
 CONFIG -= bsymbolic_functions
 
-linux:qtConfig(separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
+unix:qtConfig(separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
 
 REPACK_DIR = $$OUT_PWD/$$getConfigDir()
 
