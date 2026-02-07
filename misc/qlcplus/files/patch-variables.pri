- fix build by removing -Werror

--- variables.pri.orig	2023-06-30 07:40:55 UTC
+++ variables.pri
@@ -16,8 +16,8 @@ qmlui:  APPVERSION = 5.0.0 Beta 3
 #############################################################################
 
 # Treat all compiler warnings as errors
-QMAKE_CXXFLAGS += -Werror
-unix:QMAKE_CFLAGS += -Werror
+#QMAKE_CXXFLAGS += -Werror
+#unix:QMAKE_CFLAGS += -Werror
 
 CONFIG         += warn_on
 
