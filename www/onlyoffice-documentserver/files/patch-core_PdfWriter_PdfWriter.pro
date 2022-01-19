--- core/PdfWriter/PdfWriter.pro.orig	2021-12-18 11:22:47 UTC
+++ core/PdfWriter/PdfWriter.pro
@@ -22,6 +22,10 @@ LIBS += -L$$CORE_BUILDS_LIBRARIES_PATH -lCryptoPPLib
 
 DEFINES += NOMINMAX
 
+core_freebsd{
+    DEFINES += HAVE_UNISTD_H HAVE_FCNTL_H
+    QMAKE_CXXFLAGS += -Wno-narrowing
+}
 core_linux {
     DEFINES += HAVE_UNISTD_H HAVE_FCNTL_H
     QMAKE_CXXFLAGS += -Wno-narrowing
