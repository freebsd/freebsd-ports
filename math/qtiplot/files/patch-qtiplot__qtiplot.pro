--- ./qtiplot/qtiplot.pro.orig	2009-03-27 00:45:43.000000000 +0300
+++ ./qtiplot/qtiplot.pro	2009-03-27 00:46:10.000000000 +0300
@@ -18,7 +18,7 @@
 CONFIG          += HAVE_LIBPNG
 
 # Uncomment the following line if you want to perform a custom installation using the *.path variables defined bellow.
-#CONFIG          += CustomInstall
+CONFIG          += CustomInstall
 
 CONFIG          += release
 #CONFIG          += debug
@@ -28,13 +28,9 @@
 #!!! Warning: You must modify these paths according to your computer settings
 #############################################################################
 
-INCLUDEPATH       += ../3rdparty/muparser/include
-INCLUDEPATH       += ../3rdparty/qwtplot3d/include
-INCLUDEPATH       += ../3rdparty/qwt/src
-INCLUDEPATH       += ../3rdparty/liborigin
-INCLUDEPATH       += ../3rdparty/gsl/include
-INCLUDEPATH       += ../3rdparty/zlib
-INCLUDEPATH       += ../3rdparty/boost_1_36_0
+unix:INCLUDEPATH += $$LOCALBASE/include/qwt
+unix:INCLUDEPATH += $$LOCALBASE/include/qwtplot3d-qt4
+unix:INCLUDEPATH += $$LOCALBASE/include/boost
 
 ##################### 3rd PARTY LIBRARIES SECTION ###########################
 #!!! Warning: You must modify these paths according to your computer settings
@@ -43,17 +39,14 @@
 ##################### Linux (Mac OS X) ######################################
 
 # statically link against libraries in 3rdparty
-unix:LIBS         += ../3rdparty/muparser/lib/libmuparser.a
-unix:LIBS         += ../3rdparty/qwt/lib/libqwt.a
-unix:LIBS         += ../3rdparty/gsl/lib/libgsl.a
-unix:LIBS         += ../3rdparty/gsl/lib/libgslcblas.a
-unix:LIBS         += ../3rdparty/boost_1_36_0/lib/libboost_date_time-gcc43-mt-1_36.a
-unix:LIBS         += ../3rdparty/boost_1_36_0/lib/libboost_thread-gcc43-mt-1_36.a
 
 # dynamically link against dependencies if they are installed system-wide
-#unix:LIBS         += -lmuparser
-#unix:LIBS         += -lqwt
-#unix:LIBS         += -lgsl -lgslcblas
+unix:LIBS         += -lmuparser
+unix:LIBS         += -lqwt
+unix:LIBS         += -lgsl -lgslcblas
+unix:LIBS         += -L$$LOCALBASE/lib -lz
+unix:LIBS         += -lboost_date_time
+unix:LIBS         += -lboost_thread
 
 ##################### Windows ###############################################
 
@@ -80,18 +73,16 @@
 contains(CONFIG, CustomInstall){
 	INSTALLS        += target
 	INSTALLS        += translations
-	INSTALLS        += manual
-	INSTALLS        += documentation
 	unix:INSTALLS        += man
 
-	unix: INSTALLBASE = /usr
+	unix: INSTALLBASE = $$PREFIX
 	win32: INSTALLBASE = C:/QtiPlot
 
 	unix: target.path = $$INSTALLBASE/bin
 	unix: translations.path = $$INSTALLBASE/share/qtiplot/translations
 	unix: manual.path = $$INSTALLBASE/share/doc/qtiplot/manual
 	unix: documentation.path = $$INSTALLBASE/share/doc/qtiplot
-	unix: man.path = $$INSTALLBASE/share/man/man1/
+	unix: man.path = $$INSTALLBASE/man/man1/
 
 	win32: target.path = $$INSTALLBASE
 	win32: translations.path = $$INSTALLBASE/translations
@@ -186,17 +177,18 @@
   				    qtiUtil.py \
   				    qti_wordlist.txt \
 
-  	unix: pythonconfig.path = /usr/local/qtiplot
+  	unix: pythonconfig.path = $$INSTALLBASE/share/qtiplot
   	win32: pythonconfig.path = $$INSTALLBASE
   	DEFINES += PYTHON_CONFIG_PATH="\\\"$$replace(pythonconfig.path," ","\ ")\\\"
   }
 
   unix {
-    INCLUDEPATH += $$system(python python-includepath.py)
-    LIBS        += $$system(python -c "\"from distutils import sysconfig; print '-lpython'+sysconfig.get_config_var('VERSION')\"")
+    INCLUDEPATH += $$(PYTHON_INCLUDEDIR)
+    LIBS        += -l$$(PYTHON_VERSION)
     LIBS        += -lm
     system(mkdir -p $${SIP_DIR})
-    system($$system(python python-sipcmd.py) -c $${SIP_DIR} src/scripting/qti.sip)
+    SIPCMD = $$PYTHON_CMD python-sipcmd.py
+    system($$system($$SIPCMD) -c $${SIP_DIR} src/scripting/qti.sip)
   }
 
   win32 {
@@ -210,8 +202,8 @@
 
 contains(CONFIG, HAVE_LIBPNG){
 	DEFINES += GL2PS_HAVE_LIBPNG
-	INCLUDEPATH += ../3rdparty/libpng/
-	LIBS        += ../3rdparty/libpng/libpng.a
+	INCLUDEPATH += $$LOCALBASE/include/libpng
+	LIBS        += -lpng
 }
 
 ###############################################################
