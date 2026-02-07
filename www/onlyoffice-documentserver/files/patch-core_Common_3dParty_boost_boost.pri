--- core/Common/3dParty/boost/boost.pri.orig	2021-09-30 12:13:32 UTC
+++ core/Common/3dParty/boost/boost.pri
@@ -1,5 +1,11 @@
-INCLUDEPATH += $$PWD/build/$$CORE_BUILDS_PLATFORM_PREFIX/include
-CORE_BOOST_LIBS = $$PWD/build/$$CORE_BUILDS_PLATFORM_PREFIX/lib
+!core_freebsd {
+    INCLUDEPATH += $$PWD/build/$$CORE_BUILDS_PLATFORM_PREFIX/include
+    CORE_BOOST_LIBS = $$PWD/build/$$CORE_BUILDS_PLATFORM_PREFIX/lib
+}
+core_freebsd {
+    INCLUDEPATH += %%LOCALBASE%%/include
+    CORE_BOOST_LIBS = %%LOCALBASE%%/lib
+}
 
 core_android {
     INCLUDEPATH += $$PWD/build/android/include
