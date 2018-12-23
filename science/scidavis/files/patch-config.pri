--- config.pri.orig	2018-10-17 03:28:35 UTC
+++ config.pri
@@ -61,7 +61,7 @@ unix:message(Building with preset $$PRES
 
 ### Linux Desktop integration
 !contains(PRESET, self_contained) {
-	unix:INSTALLS   += desktop_entry mime_package mime_link icons man_page appdata
+	unix:INSTALLS   += desktop_entry mime_package icons man_page appdata
 }
 
 ################################################################################
@@ -120,7 +120,7 @@ unix {# Linux / MacOS X
 		### directory specified here or somewhere else in the python path (sys.path) where "import" can find it
 
 		### where scidavisrc.py is searched for at runtime
-		pythonconfig.path = "$$INSTALLBASE/../etc"
+		pythonconfig.path = "$$INSTALLBASE/etc"
 		### where the scidavisUtil python module is searched for at runtime
 		pythonutils.path = "$$INSTALLBASE/share/scidavis"
 
