--- core/Common/base.pri.orig	2021-09-30 12:13:32 UTC
+++ core/Common/base.pri
@@ -97,6 +97,14 @@ android {
 	DEFINES += __ANDROID__ LINUX _LINUX _ARM_ALIGN_
 }
 
+freebsd-clang {
+    message("freebsd-clang")
+    CONFIG += core_freebsd
+    CONFIG += core_freebsd_64
+    QMAKE_CC = %%CC%%
+    QMAKE_CXX = %%CXX%%
+}
+
 win32:contains(QMAKE_TARGET.arch, x86_64): {
 	CONFIG += core_win_64
 }
@@ -167,6 +175,14 @@ core_win_64 {
 	DEFINES += WIN64 _WIN64
 }
 
+core_freebsd {
+    equals(TEMPLATE, app) {
+        QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
+        QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/system\'"
+        QMAKE_LFLAGS += -Wl,--disable-new-dtags
+    }
+}
+
 core_linux {
 	DEFINES += LINUX _LINUX
 }
@@ -219,6 +235,10 @@ core_windows {
 			core_win_32:QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
 		}
 	}
+}
+
+core_freebsd_64 {
+    CORE_BUILDS_PLATFORM_PREFIX = freebsd_64
 }
 
 core_linux {
