--- core/OfficeCryptReader/ooxml_crypt/ooxml_crypt.pro.orig	2021-12-18 11:22:47 UTC
+++ core/OfficeCryptReader/ooxml_crypt/ooxml_crypt.pro
@@ -50,6 +50,11 @@ core_windows {
     LIBS += -lws2_32
 }
 
+core_freebsd {
+    LIBS += -lz -pthread
+    QMAKE_LFLAGS += -Wl,--rpath=./
+}
+
 core_linux {
     LIBS += -lz -pthread
     QMAKE_LFLAGS += -Wl,--rpath=./
