--- ./qtiplot/qtiplot.pro.orig	Sat Jun  2 15:33:23 2007
+++ ./qtiplot/qtiplot.pro	Sat Jun  2 15:35:21 2007
@@ -17,24 +17,17 @@
 
 # what to install and where
 INSTALLS        += target
-INSTALLS        += documentation
-unix: target.path = /usr/bin
+#INSTALLS        += documentation
+unix: target.path = $$(PREFIX)
 unix: documentation.path = /usr/share/doc/qtiplot
 
 ##################### 3rd PARTY HEADER FILES SECTION ########################
 #!!! Warning: You must modify these paths according to your computer settings
 #############################################################################
 
-INCLUDEPATH       += ../3rdparty/muParser
-
-INCLUDEPATH       += ../3rdparty/qwtplot3d/include
-INCLUDEPATH       += ../3rdparty/qwt/src
-#INCLUDEPATH       += /usr/include/qwtplot3d
-#INCLUDEPATH       += /usr/include/qwt5
-
-INCLUDEPATH       += ../3rdparty/liborigin
-INCLUDEPATH       += ../3rdparty/gsl/include
-INCLUDEPATH       += ../3rdparty/zlib123/include
+unix:INCLUDEPATH += $$(LOCALBASE)/include
+unix:INCLUDEPATH += $$(LOCALBASE)/include/qwt
+unix:INCLUDEPATH += $$(LOCALBASE)/include/qwtplot3d-qt4
 
 ##################### 3rd PARTY LIBRARIES SECTION ###########################
 #!!! Warning: You must modify these paths according to your computer settings
@@ -47,18 +40,18 @@
 unix:LIBS         += -L /usr/lib$${libsuff}
 
 # statically link against Qwt(3D) in 3rdparty
-unix:LIBS         += ../3rdparty/qwtplot3d/lib/libqwtplot3d.a
-unix:LIBS         += ../3rdparty/qwt/lib/libqwt.a
+unix:LIBS         += -L$$(LOCALBASE)/lib -lqwt -lqwtplot3d-qt4 -lorigin
+unix:LIBS         += -lz -lmuparser
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
 
@@ -110,8 +103,8 @@
                   translations/qtiplot_ja.ts \
                   translations/qtiplot_sv.ts
 
-#system(lupdate -verbose qtiplot.pro)
-#system(lrelease -verbose qtiplot.pro)
+system($$(LOCALBASE)/bin/lupdate-qt4 -verbose qtiplot.pro)
+system($$(LOCALBASE)/bin/lrelease-qt4 -verbose qtiplot.pro)
 
 ###################### DOCUMENTATION ########################################
 
@@ -350,8 +343,8 @@
 ################# Origin Import (liborigin) ###################
 ###############################################################
 
-HEADERS += ../3rdparty/liborigin/OPJFile.h
-SOURCES += ../3rdparty/liborigin/OPJFile.cpp
+#HEADERS += ../3rdparty/liborigin/OPJFile.h
+#SOURCES += ../3rdparty/liborigin/OPJFile.cpp
 
 ###############################################################
 ##################### SCRIPTING LANGUAGES SECTION #############
@@ -361,30 +354,32 @@
 
 contains(SCRIPTING_LANGS, muParser) {
   DEFINES += SCRIPTING_MUPARSER
-
+  
+  unix:LIBS +=	-lmuparser
+  
   HEADERS += src/muParserScript.h \
              src/muParserScripting.h \
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
+#              ../3rdparty/muParser/muParser.h \
+#              ../3rdparty/muParser/muParserBase.h \
+#              ../3rdparty/muParser/muParserInt.h \
+#              ../3rdparty/muParser/muParserError.h \
+#              ../3rdparty/muParser/muParserStack.h \
+#              ../3rdparty/muParser/muParserToken.h \
+#              ../3rdparty/muParser/muParserBytecode.h \
+#              ../3rdparty/muParser/muParserCallback.h \
+#              ../3rdparty/muParser/muParserTokenReader.h \
+#              ../3rdparty/muParser/muParserFixes.h \
+#              ../3rdparty/muParser/muParserDef.h \
 
   SOURCES += src/muParserScript.cpp \
              src/muParserScripting.cpp \
-             ../3rdparty/muParser/muParser.cpp \
-             ../3rdparty/muParser/muParserBase.cpp \
-             ../3rdparty/muParser/muParserInt.cpp \
-             ../3rdparty/muParser/muParserBytecode.cpp \
-             ../3rdparty/muParser/muParserCallback.cpp \
-             ../3rdparty/muParser/muParserTokenReader.cpp \
-             ../3rdparty/muParser/muParserError.cpp \
+#              ../3rdparty/muParser/muParser.cpp \
+#              ../3rdparty/muParser/muParserBase.cpp \
+#              ../3rdparty/muParser/muParserInt.cpp \
+#              ../3rdparty/muParser/muParserBytecode.cpp \
+#              ../3rdparty/muParser/muParserCallback.cpp \
+#              ../3rdparty/muParser/muParserTokenReader.cpp \
+#              ../3rdparty/muParser/muParserError.cpp \
 
 }
 
@@ -396,12 +391,11 @@
   SOURCES += src/PythonScript.cpp src/PythonScripting.cpp
 
   unix {
-    INCLUDEPATH += $$system(python python-includepath.py)
-    LIBS        += $$system(python -c "\"from distutils import sysconfig; print '-lpython'+sysconfig.get_config_var('VERSION')\"")
-    LIBS        += -lm
-    system(mkdir -p $${SIP_DIR})
-    system($$system(python python-sipcmd.py) -c $${SIP_DIR} src/qti.sip)
-  }
+	INCLUDEPATH += $$(PYTHON_INCLUDEDIR)
+	LIBS +=	-lm -l$$(PYTHON_VERSION)
+	system(mkdir -p $${SIP_DIR})
+	system($$(PYTHON_VERSION) -c $${SIP_DIR} src/qti.sip)
+	}
 
   win32 {
     INCLUDEPATH += $$system(call python-includepath.py)
