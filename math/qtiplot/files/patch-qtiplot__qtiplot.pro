--- ./qtiplot/qtiplot.pro.orig	2011-10-15 23:30:36.976081538 +0000
+++ ./qtiplot/qtiplot.pro	2011-10-15 23:31:17.153088752 +0000
@@ -45,14 +45,14 @@
 	INSTALLS        += documentation
 	unix:INSTALLS        += man
 
-	unix: INSTALLBASE = /usr
+	unix: INSTALLBASE = $$PREFIX
 	win32: INSTALLBASE = C:/QtiPlot
 
 	unix: target.path = $$INSTALLBASE/bin
 	unix: translations.path = $$INSTALLBASE/share/qtiplot/translations
-	unix: manual.path = $$INSTALLBASE/share/doc/qtiplot/manual
+	unix: manual.path = $$INSTALLBASE/share/qtiplot/manual
 	unix: documentation.path = $$INSTALLBASE/share/doc/qtiplot
-	unix: man.path = $$INSTALLBASE/share/man/man1/
+	unix: man.path = $$INSTALLBASE/man/man1/
 
 	win32: target.path = $$INSTALLBASE
 	win32: translations.path = $$INSTALLBASE/translations
@@ -101,17 +101,7 @@
 		  translations/qtiplot_ja.ts \
 		  translations/qtiplot_sv.ts
 
-translations.files += translations/qtiplot_cn.qm \
-		translations/qtiplot_cz.qm \
-		translations/qtiplot_de.qm \
-		translations/qtiplot_es.qm \
-		translations/qtiplot_el.qm \
-		translations/qtiplot_fr.qm \
-		translations/qtiplot_pt.qm \
-		translations/qtiplot_ro.qm \
-		translations/qtiplot_ru.qm \
-		translations/qtiplot_ja.qm \
-		translations/qtiplot_sv.qm
+translations.files += $$replace(TRANSLATIONS,".ts",".qm")
 
 isEmpty(LUPDATE): LUPDATE = lupdate
 #system($$LUPDATE -verbose qtiplot.pro)
@@ -120,11 +110,7 @@
 
 ###################### DOCUMENTATION ########################################
 
-manual.files += ../manual/html \
-                ../manual/qtiplot-manual-en.pdf
 
-documentation.files += ../README.html \
-                       ../gpl_licence.txt
 
 unix: man.files += ../qtiplot.1
 
@@ -159,18 +145,19 @@
   				    qtiUtil.py \
   				    qti_wordlist.txt \
 
-  	unix: pythonconfig.path = /usr/local/qtiplot
+  	unix: pythonconfig.path = $$INSTALLBASE/share/qtiplot
   	win32: pythonconfig.path = $$INSTALLBASE
   	DEFINES += PYTHON_CONFIG_PATH="\\\"$$replace(pythonconfig.path," ","\ ")\\\"
   }
 
   unix {
     isEmpty(PYTHON): PYTHON = python
-    INCLUDEPATH += $$system($$PYTHON python-includepath.py)
-    LIBS        += $$system($$PYTHON -c "\"from distutils import sysconfig; print '-lpython'+sysconfig.get_config_var('VERSION')\"")
+    INCLUDEPATH += $$(PYTHON_INCLUDEDIR)
+    LIBS        += -l$$(PYTHON_VERSION)
     LIBS        += -lm
     system(mkdir -p $${SIP_DIR})
-    system($$system($$PYTHON python-sipcmd.py) -c $${SIP_DIR} src/scripting/qti.sip)
+    SIPCMD = $$PYTHON_CMD python-sipcmd.py
+    system($$system($$SIPCMD) -c $${SIP_DIR} src/scripting/qti.sip)
   }
 
   win32 {
