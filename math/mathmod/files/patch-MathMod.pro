--- MathMod.pro.orig	2016-03-03 21:15:56 UTC
+++ MathMod.pro
@@ -58,7 +58,6 @@ FORMS     = ui_forms/drawingoptions.ui \
 			 
 RC_FILE 	= mm.rc
 RESOURCES  += myressources.qrc
-LIBS += -lopengl32
 QT         += opengl widgets
 
 OTHER_FILES += \
