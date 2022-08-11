--- src/dvbcut.pro.orig	2018-08-19 23:08:52 UTC
+++ src/dvbcut.pro
@@ -112,9 +112,9 @@ system(pkg-config --exists ao) {
     PKGCONFIG += ao
 } else { error(Please install development package libao-dev) }
 
-system(pkg-config --exists mad) {
+system(pkg-config --exists libmad) {
     QMAKE_CXXFLAGS += -DHAVE_LIB_MAD
-    PKGCONFIG += mad
+    PKGCONFIG += libmad
 } else { error(Please install development package libmad0-dev) }
 
 QMAKE_CXXFLAGS += -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -D_FILE_OFFSET_BITS=64
