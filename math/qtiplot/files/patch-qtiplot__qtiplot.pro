--- ./qtiplot/qtiplot.pro.orig	2008-03-29 10:43:50.000000000 +0300
+++ ./qtiplot/qtiplot.pro	2008-03-29 10:46:00.000000000 +0300
@@ -45,12 +45,8 @@
 #!!! Warning: You must modify these paths according to your computer settings
 #############################################################################
 
-INCLUDEPATH       += ../3rdparty/muparser/include
-INCLUDEPATH       += ../3rdparty/qwtplot3d/include
-INCLUDEPATH       += ../3rdparty/qwt/src
-INCLUDEPATH       += ../3rdparty/liborigin
-INCLUDEPATH       += ../3rdparty/gsl/include
-INCLUDEPATH       += ../3rdparty/zlib123/include
+unix:INCLUDEPATH += $$LOCALBASE/include/qwt
+unix:INCLUDEPATH += $$LOCALBASE/include/qwtplot3d-qt4
 
 ##################### 3rd PARTY LIBRARIES SECTION ###########################
 #!!! Warning: You must modify these paths according to your computer settings
@@ -59,17 +55,13 @@
 ##################### Linux (Mac OS X) ######################################
 
 # statically link against libraries in 3rdparty
-unix:LIBS         += ../3rdparty/muparser/lib/libmuparser.a
-unix:LIBS         += ../3rdparty/qwtplot3d/lib/libqwtplot3d.a
-unix:LIBS         += ../3rdparty/qwt/lib/libqwt.a
-unix:LIBS         += ../3rdparty/gsl/lib/libgsl.a
-unix:LIBS         += ../3rdparty/gsl/lib/libgslcblas.a
 
 # dynamically link against dependencies if they are installed system-wide
 #unix:LIBS         += -lmuparser
 #unix:LIBS         += -lqwtplot3d
-#unix:LIBS         += -lqwt
-#unix:LIBS         += -lgsl -lgslcblas
+unix:LIBS         += -lqwt
+unix:LIBS         += -lgsl -lgslcblas
+unix:LIBS         += -L$$LOCALBASE/lib -lqwtplot3d-qt4 -lz
 
 ##################### Windows ###############################################
 
@@ -435,6 +427,7 @@
 ##################### Default: muParser v1.28 #################
 
 contains(SCRIPTING_LANGS, muParser) {
+  unix:LIBS         += -lmuparser
   DEFINES += SCRIPTING_MUPARSER
 
   HEADERS += src/muParserScript.h \
@@ -461,11 +454,12 @@
   SOURCES += src/PythonScript.cpp src/PythonScripting.cpp
 
   unix {
-    INCLUDEPATH += $$system(python python-includepath.py)
-    LIBS        += $$system(python -c "\"from distutils import sysconfig; print '-lpython'+sysconfig.get_config_var('VERSION')\"")
+    INCLUDEPATH += $$(PYTHON_INCLUDEDIR)
+    LIBS        += -l$$(PYTHON_VERSION)
     LIBS        += -lm
     system(mkdir -p $${SIP_DIR})
-    system($$system(python python-sipcmd.py) -c $${SIP_DIR} src/qti.sip)
+    SIPCMD = $$PYTHON_CMD python-sipcmd.py
+    system($$system($$SIPCMD) -c $${SIP_DIR} src/qti.sip)
   }
 
   win32 {
