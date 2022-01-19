--- core/UnicodeConverter/UnicodeConverter.pro.orig	2021-09-30 12:13:32 UTC
+++ core/UnicodeConverter/UnicodeConverter.pro
@@ -15,6 +15,11 @@ include(../Common/base.pri)
 DEFINES += UNICODECONVERTER_USE_DYNAMIC_LIBRARY
 ADD_DEPENDENCY(kernel)
 
+core_freebsd {    
+    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
+    QMAKE_LFLAGS += -Wl,--disable-new-dtags
+}
+
 core_linux {    
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
     QMAKE_LFLAGS += -Wl,--disable-new-dtags
