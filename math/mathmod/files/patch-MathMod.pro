--- MathMod.pro.orig	2016-11-18 21:27:55 UTC
+++ MathMod.pro
@@ -68,10 +68,10 @@ OTHER_FILES += \
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
