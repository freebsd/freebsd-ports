--- core/OfficeUtils/OfficeUtils.pri.orig	2021-12-18 10:21:34 UTC
+++ core/OfficeUtils/OfficeUtils.pri
@@ -1,3 +1,6 @@
+core_freebsd {
+    QMAKE_CXXFLAGS += -Wall -Wno-ignored-qualifiers
+}
 core_linux {
     QMAKE_CXXFLAGS += -Wall -Wno-ignored-qualifiers
 }
