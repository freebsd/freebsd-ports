--- core/X2tConverter/build/Qt/X2tConverter.pri.orig	2021-09-30 12:13:32 UTC
+++ core/X2tConverter/build/Qt/X2tConverter.pri
@@ -111,5 +111,9 @@ core_windows {
 core_windows {
     LIBS += -lAdvapi32
 }
+core_freebsd {
+    LIBS += -liconv -lharfbuzz
+    QMAKE_CXXFLAGS += -Wno-narrowing
+}
 ########################################################
 
