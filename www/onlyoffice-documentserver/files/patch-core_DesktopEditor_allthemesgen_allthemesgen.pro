--- core/DesktopEditor/allthemesgen/allthemesgen.pro.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/allthemesgen/allthemesgen.pro
@@ -33,4 +33,11 @@ core_linux {
     QMAKE_LFLAGS += -Wl,--rpath=./
 }
 
+core_freebsd {
+    LIBS += -lz -pthread -liconv
+
+    QMAKE_LFLAGS += -Wl,--rpath=./
+}
+
+
 SOURCES += main.cpp
