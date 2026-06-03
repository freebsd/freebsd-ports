--- core/PdfFile/PdfFile.pro.orig	2025-08-02 18:33:34 UTC
+++ core/PdfFile/PdfFile.pro
@@ -110,6 +110,11 @@ DEFINES += CRYPTOPP_DISABLE_ASM \
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
