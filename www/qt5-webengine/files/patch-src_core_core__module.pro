* Do not pass --no-undefined and -z,defs to the linker because of environ(7).
* Extend some Linux-only compiler arguments to FreeBSD.
* Generate split out debug files on FreeBSD too.

--- src/core/core_module.pro.orig	2017-04-20 22:41:02 UTC
+++ src/core/core_module.pro
@@ -4,6 +4,9 @@ include(core_common.pri)
 # Needed to set a CFBundleIdentifier
 QMAKE_INFO_PLIST = Info_mac.plist
 
+# Do not pass --no-undefined to the linker because of environ(7) usage.
+freebsd: QMAKE_LFLAGS_NOUNDEF =
+
 linking_pri = $$OUT_PWD/$$getConfigDir()/$${TARGET}.pri
 
 !include($$linking_pri) {
@@ -29,15 +32,15 @@ RSP_FILE = $$OUT_PWD/$$getConfigDir()/$${TARGET}.rsp
 for(object, NINJA_OBJECTS): RSP_CONTENT += $$object
 write_file($$RSP_FILE, RSP_CONTENT)
 macos:LIBS_PRIVATE += -Wl,-filelist,$$shell_quote($$RSP_FILE)
-linux:LIBS_PRIVATE += @$$RSP_FILE
+unix:LIBS_PRIVATE += @$$RSP_FILE
 # QTBUG-58710 add main rsp file on windows
 win32:QMAKE_LFLAGS += @$$RSP_FILE
-linux: LIBS_PRIVATE += -Wl,--start-group $$NINJA_ARCHIVES -Wl,--end-group
+unix: LIBS_PRIVATE += -Wl,--start-group $$NINJA_ARCHIVES -Wl,--end-group
 else: LIBS_PRIVATE += $$NINJA_ARCHIVES
 LIBS_PRIVATE += $$NINJA_LIB_DIRS $$NINJA_LIBS
 # GN's LFLAGS doesn't always work across all the Linux configurations we support.
 # The Windows and macOS ones from GN does provide a few useful flags however
-linux: QMAKE_LFLAGS += -Wl,--gc-sections -Wl,-O1 -Wl,-z,now -Wl,-z,defs
+unix: QMAKE_LFLAGS += -Wl,--gc-sections -Wl,-O1 -Wl,-z,now
 else: QMAKE_LFLAGS += $$NINJA_LFLAGS
 POST_TARGETDEPS += $$NINJA_TARGETDEPS
 
@@ -67,7 +70,7 @@ CONFIG -= bsymbolic_functions
 
 qtConfig(egl): CONFIG += egl
 
-linux:qtConfig(separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
+unix:qtConfig(separate_debug_info): QMAKE_POST_LINK="cd $(DESTDIR) && $(STRIP) --strip-unneeded $(TARGET)"
 
 REPACK_DIR = $$OUT_PWD/$$getConfigDir()
 
