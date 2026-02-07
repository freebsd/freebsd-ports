--- src/core/api/core_api.pro.orig	2020-03-16 14:04:24 UTC
+++ src/core/api/core_api.pro
@@ -66,7 +66,7 @@ SOURCES = \
     qwebengineurlschemehandler.cpp
 
 ### Qt6 Remove this workaround
-unix:!isEmpty(QMAKE_LFLAGS_VERSION_SCRIPT):!static {
+linux:!isEmpty(QMAKE_LFLAGS_VERSION_SCRIPT):!static {
     SOURCES += qtbug-60565.cpp \
                qtbug-61521.cpp
 }
