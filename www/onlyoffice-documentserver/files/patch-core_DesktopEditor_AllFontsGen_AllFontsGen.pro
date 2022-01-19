--- core/DesktopEditor/AllFontsGen/AllFontsGen.pro.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/AllFontsGen/AllFontsGen.pro
@@ -39,4 +39,10 @@ core_linux {
     QMAKE_LFLAGS += -Wl,--rpath=./
 }
 
+core_freebsd {
+    LIBS += -lz -pthread -liconv
+
+    QMAKE_LFLAGS += -Wl,--rpath=./
+}
+
 SOURCES += main.cpp
