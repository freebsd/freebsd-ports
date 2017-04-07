--- tools/install_sdk/install_sdk.pro.orig	2017-04-06 20:20:44 UTC
+++ tools/install_sdk/install_sdk.pro
@@ -67,7 +67,7 @@ greaterThan(QT_MAJOR_VERSION, 4) {
   MODULE_PRF_FILE = $$OUT_PWD/mkspecs/features/$${MODULE}.prf
   NEW_LIB = $${LIBPREFIX}Qt$${QT_MAJOR_VERSION}$${MODULE_NAME}$${NAME_SUF}.$${LIBSUFFIX}
   NEW_LIB_D = $${LIBPREFIX}Qt$${QT_MAJOR_VERSION}$${MODULE_NAME}$${NAME_SUF}$${DEBUG_SUF}.$${LIBSUFFIX}
-  MKSPECS_DIR = $$[QT_INSTALL_BINS]/../mkspecs
+  MKSPECS_DIR = $$[QT_INSTALL_ARCHDATA]/mkspecs
 } else {
   MODULE_PRF_FILE = $$PWD/qt4/$${MODULE}.prf
   NEW_LIB = $${ORIG_LIB}
