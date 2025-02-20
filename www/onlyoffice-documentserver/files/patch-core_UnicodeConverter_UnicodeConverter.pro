--- core/UnicodeConverter/UnicodeConverter.pro.orig	2021-09-30 12:13:32 UTC
+++ core/UnicodeConverter/UnicodeConverter.pro
@@ -13,6 +13,12 @@ DEFINES += UNICODECONVERTER_USE_DYNAMIC_LIBRARY
 
 DEFINES += UNICODECONVERTER_USE_DYNAMIC_LIBRARY
 
+core_freebsd {    
+    CONFIG += c++17
+    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
+    QMAKE_LFLAGS += -Wl,--disable-new-dtags
+}
+
 core_linux {    
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
     QMAKE_LFLAGS += -Wl,--disable-new-dtags
