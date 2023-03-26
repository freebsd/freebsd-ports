--- core/PdfFile/PdfFile.pro.orig	2023-02-13 12:29:53.978119000 +0100
+++ core/PdfFile/PdfFile.pro	2023-02-13 12:30:22.230355000 +0100
@@ -113,6 +113,11 @@ LIBS += -L$$CORE_BUILDS_LIBRARIES_PATH -lCryptoPPLib
            NOMINMAX
 LIBS += -L$$CORE_BUILDS_LIBRARIES_PATH -lCryptoPPLib
 
+core_freebsd {
+    DEFINES += HAVE_UNISTD_H \
+               HAVE_FCNTL_H
+    QMAKE_CXXFLAGS += -Wno-narrowing
+}
 core_linux {
     DEFINES += HAVE_UNISTD_H \
                HAVE_FCNTL_H
