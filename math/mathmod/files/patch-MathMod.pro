--- MathMod.pro.orig	2025-01-08 20:23:35 UTC
+++ MathMod.pro
@@ -63,7 +63,7 @@ OTHER_FILES     += \
                 mathmodcollection.js \
                 mathmodconfig.js
 # install
-target.path    = $TARGET
+target.path    = $$INSTALL_ROOT/$$PREFIX/bin/
 sources.files  = $$SOURCES $$HEADERS $$RESOURCES $$FORMS mathmod.pro
 sources.path   = $TARGET
-INSTALLS      += target sources
+INSTALLS      += target
