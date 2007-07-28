--- ./qtiplot/qtiplot.pro.orig	Sat Jul 14 14:56:13 2007
+++ ./qtiplot/qtiplot.pro	Sat Jul 14 15:01:25 2007
@@ -25,12 +25,8 @@
 #!!! Warning: You must modify these paths according to your computer settings
 #############################################################################
 
-INCLUDEPATH       += ../3rdparty/muParser
-INCLUDEPATH       += ../3rdparty/qwtplot3d/include
-INCLUDEPATH       += ../3rdparty/qwt/src
-INCLUDEPATH       += ../3rdparty/liborigin
-INCLUDEPATH       += ../3rdparty/gsl/include
-INCLUDEPATH       += ../3rdparty/zlib123/include
+unix:INCLUDEPATH += $$(LOCALBASE)/include/qwt
+unix:INCLUDEPATH += $$(LOCALBASE)/include/qwtplot3d-qt4
 
 ##################### 3rd PARTY LIBRARIES SECTION ###########################
 #!!! Warning: You must modify these paths according to your computer settings
@@ -43,18 +39,17 @@
 unix:LIBS         += -L /usr/lib$${libsuff}
 
 # statically link against Qwt(3D) in 3rdparty
-unix:LIBS         += ../3rdparty/qwtplot3d/lib/libqwtplot3d.a
-unix:LIBS         += ../3rdparty/qwt/lib/libqwt.a
+unix:LIBS         += -L$$(LOCALBASE)/lib -lqwt -lqwtplot3d-qt4 -lz
 # dynamically link against Qwt(3D) installed system-wide
 # WARNING: make sure they are compiled against Qt4
 #unix:LIBS         += -lqwtplot3d
 #unix:LIBS         += -lqwt
 
 # statically link against GSL in 3rdparty
-unix:LIBS         += ../3rdparty/gsl/lib/libgsl.a
-unix:LIBS         += ../3rdparty/gsl/lib/libgslcblas.a
+#unix:LIBS         += ../3rdparty/gsl/lib/libgsl.a
+#unix:LIBS         += ../3rdparty/gsl/lib/libgslcblas.a
 #dynamically link against GSL installed system-wide
-#unix:LIBS         += -lgsl -lgslcblas
+unix:LIBS         += -lgsl -lgslcblas
 
 ##################### Windows ###############################################
 
@@ -359,30 +354,12 @@
 
 contains(SCRIPTING_LANGS, muParser) {
   DEFINES += SCRIPTING_MUPARSER
-
+  unix:LIBS         += -lmuparser
   HEADERS += src/muParserScript.h \
-             src/muParserScripting.h \
-             ../3rdparty/muParser/muParser.h \
-             ../3rdparty/muParser/muParserBase.h \
-             ../3rdparty/muParser/muParserInt.h \
-             ../3rdparty/muParser/muParserError.h \
-             ../3rdparty/muParser/muParserStack.h \
-             ../3rdparty/muParser/muParserToken.h \
-             ../3rdparty/muParser/muParserBytecode.h \
-             ../3rdparty/muParser/muParserCallback.h \
-             ../3rdparty/muParser/muParserTokenReader.h \
-             ../3rdparty/muParser/muParserFixes.h \
-             ../3rdparty/muParser/muParserDef.h \
+             src/muParserScripting.h
 
   SOURCES += src/muParserScript.cpp \
-             src/muParserScripting.cpp \
-             ../3rdparty/muParser/muParser.cpp \
-             ../3rdparty/muParser/muParserBase.cpp \
-             ../3rdparty/muParser/muParserInt.cpp \
-             ../3rdparty/muParser/muParserBytecode.cpp \
-             ../3rdparty/muParser/muParserCallback.cpp \
-             ../3rdparty/muParser/muParserTokenReader.cpp \
-             ../3rdparty/muParser/muParserError.cpp \
+             src/muParserScripting.cpp
 
 }
 
@@ -394,11 +371,11 @@
   SOURCES += src/PythonScript.cpp src/PythonScripting.cpp
 
   unix {
-    INCLUDEPATH += $$system(python python-includepath.py)
-    LIBS        += $$system(python -c "\"from distutils import sysconfig; print '-lpython'+sysconfig.get_config_var('VERSION')\"")
-    LIBS        += -lm
-    system(mkdir -p $${SIP_DIR})
-    system($$system(python python-sipcmd.py) -c $${SIP_DIR} src/qti.sip)
+	INCLUDEPATH += $$(PYTHON_INCLUDEDIR)
+	LIBS +=	-lm -l$$(PYTHON_VERSION)
+	system(mkdir -p $${SIP_DIR})
+	SIPCMD = $$(PYTHON_VERSION) python-sipcmd.py
+	system($$system($$SIPCMD) -c $${SIP_DIR} src/qti.sip)
   }
 
   win32 {
