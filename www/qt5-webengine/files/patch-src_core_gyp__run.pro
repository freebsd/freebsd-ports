Include the freebsd.pri file provided by the port, to pass FreeBSD specific
settings to gyp.

--- src/core/gyp_run.pro.orig	2017-04-11 14:08:46 UTC
+++ src/core/gyp_run.pro
@@ -15,6 +15,7 @@ cross_compile {
     linux: include(config/desktop_linux.pri)
     mac: include(config/mac_osx.pri)
     win32: include(config/windows.pri)
+    freebsd: include(config/freebsd.pri)
 }
 GYP_CONFIG += qtwe_process_name_debug=$$QTWEBENGINEPROCESS_NAME_DEBUG
 GYP_CONFIG += qtwe_process_name_release=$$QTWEBENGINEPROCESS_NAME_RELEASE
