--- src/core/api/core_api.pro.orig	2018-04-10 14:50:39 UTC
+++ src/core/api/core_api.pro
@@ -53,7 +53,7 @@ SOURCES = \
     qwebengineurlschemehandler.cpp
 
 ### Qt6 Remove this workaround
-unix:!isEmpty(QMAKE_LFLAGS_VERSION_SCRIPT):!static {
+linux:!isEmpty(QMAKE_LFLAGS_VERSION_SCRIPT):!static {
     SOURCES += qtbug-60565.cpp \
                qtbug-61521.cpp
 }
