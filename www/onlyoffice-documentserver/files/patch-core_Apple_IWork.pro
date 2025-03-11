--- core/Apple/IWork.pro.orig	2025-03-08 16:31:03.447633000 +0100
+++ core/Apple/IWork.pro	2025-03-08 17:07:58.170674000 +0100
@@ -10,6 +10,14 @@ DEFINES += IWORK_USE_DYNAMIC_LIBRARY
 
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
@@ -38,8 +46,8 @@ include($$CORE_ROOT_DIR/Common/3dParty/apple/apple.pri
 include($$CORE_ROOT_DIR/Common/3dParty/apple/apple.pri)
 
 # TEST
-HEADERS += $$ODF_LIB_ROOT/test/StringDocumentHandler.h
-SOURCES += $$ODF_LIB_ROOT/test/StringDocumentHandler.cxx
+#HEADERS += $$ODF_LIB_ROOT/test/StringDocumentHandler.h
+#SOURCES += $$ODF_LIB_ROOT/test/StringDocumentHandler.cxx
 
 SOURCES += IWork.cpp
 
