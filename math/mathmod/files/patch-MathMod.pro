--- MathMod.pro.orig	2021-03-08 16:59:36 UTC
+++ MathMod.pro
@@ -64,10 +64,10 @@ OTHER_FILES     += \
                 mathmodcollection.js \
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
