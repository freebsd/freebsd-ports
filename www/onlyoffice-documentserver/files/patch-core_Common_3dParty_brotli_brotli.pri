--- core/Common/3dParty/brotli/brotli.pri.orig	2025-10-13 15:33:25 UTC
+++ core/Common/3dParty/brotli/brotli.pri
@@ -1,9 +1,4 @@
-SRC_DIR = $$PWD/brotli/c
 DEFINES += FT_CONFIG_OPTION_USE_BROTLI
 
-INCLUDEPATH += \
-  $$SRC_DIR/include
-
-SOURCES += $$files($$SRC_DIR/common/*.c)
-SOURCES += $$files($$SRC_DIR/dec/*.c)
-#SOURCES += $$files($$SRC_DIR/enc/*.c)
+INCLUDEPATH += %%LOCALBASE%%/include
+LIBS        += -L%%LOCALBASE%%/lib -lbrotlicommon -lbrotlidec
