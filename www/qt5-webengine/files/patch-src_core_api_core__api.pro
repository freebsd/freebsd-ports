--- src/core/api/core_api.pro.orig	2018-11-27 04:10:38 UTC
+++ src/core/api/core_api.pro
@@ -58,7 +58,7 @@ SOURCES = \
     qwebengineurlschemehandler.cpp
 
 ### Qt6 Remove this workaround
-unix:!isEmpty(QMAKE_LFLAGS_VERSION_SCRIPT):!static {
+linux:!isEmpty(QMAKE_LFLAGS_VERSION_SCRIPT):!static {
     CONFIG -= warning_clean
     SOURCES += qtbug-60565.cpp \
                qtbug-61521.cpp
