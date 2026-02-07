--- core/Common/3dParty/icu/icu.pri.orig	2025-10-13 15:33:25 UTC
+++ core/Common/3dParty/icu/icu.pri
@@ -25,6 +25,13 @@
     LIBS        += $$PWD/$$CORE_BUILDS_PLATFORM_PREFIX/build/libicudata.so.$$ICU_MAJOR_VER
 }
 
+core_freebsd {
+    INCLUDEPATH += %%LOCALBASE%%/include
+
+    LIBS        += %%LOCALBASE%%/lib/libicuuc.so
+    LIBS        += %%LOCALBASE%%/lib/libicudata.so
+}
+
 core_mac {
     INCLUDEPATH += $$PWD/$$CORE_BUILDS_PLATFORM_PREFIX/build/include
 
