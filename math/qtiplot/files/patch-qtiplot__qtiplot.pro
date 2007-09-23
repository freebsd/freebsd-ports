--- ./qtiplot/qtiplot.pro.orig	2007-09-20 15:55:53.000000000 +0400
+++ ./qtiplot/qtiplot.pro	2007-09-23 01:11:43.000000000 +0400
@@ -30,12 +30,8 @@
 #!!! Warning: You must modify these paths according to your computer settings
 #############################################################################
 
-INCLUDEPATH       += ../3rdparty/muparser/include
-INCLUDEPATH       += ../3rdparty/qwtplot3d/include
-INCLUDEPATH       += ../3rdparty/qwt/src
-INCLUDEPATH       += ../3rdparty/liborigin
-INCLUDEPATH       += ../3rdparty/gsl/include
-INCLUDEPATH       += ../3rdparty/zlib123/include
+unix:INCLUDEPATH += $$(LOCALBASE)/include/qwt
+unix:INCLUDEPATH += $$(LOCALBASE)/include/qwtplot3d-qt4
 
 ##################### 3rd PARTY LIBRARIES SECTION ###########################
 #!!! Warning: You must modify these paths according to your computer settings
@@ -44,17 +40,13 @@
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
+unix:LIBS         += -L$$(LOCALBASE)/lib -lqwtplot3d-qt4 -lz
 
 ##################### Windows ###############################################
 
@@ -363,6 +355,7 @@
 ##################### Default: muParser v1.28 #################
 
 contains(SCRIPTING_LANGS, muParser) {
+  unix:LIBS         += -lmuparser
   DEFINES += SCRIPTING_MUPARSER
 
   HEADERS += src/muParserScript.h \
@@ -380,11 +373,11 @@
   SOURCES += src/PythonScript.cpp src/PythonScripting.cpp
 
   unix {
-    INCLUDEPATH += $$system(python python-includepath.py)
-    LIBS        += $$system(python -c "\"from distutils import sysconfig; print '-lpython'+sysconfig.get_config_var('VERSION')\"")
-    LIBS        += -lm
+    INCLUDEPATH += $$(PYTHON_INCLUDEDIR)
+    LIBS +=	-lm -l$$(PYTHON_VERSION)
     system(mkdir -p $${SIP_DIR})
-    system($$system(python python-sipcmd.py) -c $${SIP_DIR} src/qti.sip)
+    SIPCMD = $$(PYTHON_VERSION) python-sipcmd.py
+    system($$system($$SIPCMD) -c $${SIP_DIR} src/qti.sip)
   }
 
   win32 {