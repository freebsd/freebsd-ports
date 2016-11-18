--- MathMod.pro.orig	2016-11-18 12:53:17 UTC
+++ MathMod.pro
@@ -58,7 +58,6 @@ FORMS     = ui_forms/drawingoptions.ui \
 			 
 RC_FILE 	= mm.rc
 RESOURCES  += myressources.qrc
-LIBS += -lopengl32
 QT         += opengl widgets
 
 OTHER_FILES += \
@@ -67,10 +66,10 @@ OTHER_FILES += \
 			mathmodconfig.js
 
 # install
-target.path    = $TARGET
+target.path    = $$INSTALL_ROOT/$$PREFIX/bin/
 sources.files  = $$SOURCES $$HEADERS $$RESOURCES $$FORMS mathmod.pro
 sources.path   = $TARGET
-INSTALLS      += target sources
+INSTALLS      += target
 
 DISTFILES += \
     advancedmodels.js
