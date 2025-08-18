--- core/Apple/IWork.pro.orig	2025-08-02 18:33:34 UTC
+++ core/Apple/IWork.pro
@@ -10,6 +10,14 @@ CONFIG += plugin
 
 DEFINES += IWORK_USE_DYNAMIC_LIBRARY
 
+INCLUDEPATH += %%LOCALBASE%%/include/librevenge-0.0
+INCLUDEPATH += %%LOCALBASE%%/include/libetonyek-0.1
+INCLUDEPATH += %%LOCALBASE%%/include/libodfgen-0.1
+
+LIBS += %%LOCALBASE%%/lib/librevenge-0.0.so
+LIBS += %%LOCALBASE%%/lib/libetonyek-0.1.so
+LIBS += %%LOCALBASE%%/lib/libodfgen-0.1.so
+
 CORE_ROOT_DIR = $$PWD/..
 PWD_ROOT_DIR = $$PWD
 include($$CORE_ROOT_DIR/Common/base.pri)
@@ -38,8 +46,8 @@ include($$PWD/../DesktopEditor/xml/build/qt/libxml2.pr
 include($$CORE_ROOT_DIR/Common/3dParty/apple/apple.pri)
 
 # TEST
-HEADERS += $$ODF_LIB_ROOT/test/StringDocumentHandler.h
-SOURCES += $$ODF_LIB_ROOT/test/StringDocumentHandler.cxx
+#HEADERS += $$ODF_LIB_ROOT/test/StringDocumentHandler.h
+#SOURCES += $$ODF_LIB_ROOT/test/StringDocumentHandler.cxx
 
 SOURCES += IWork.cpp
 
