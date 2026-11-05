--- src/MEDLoader/MeshFormatReader.hxx.orig	2023-06-19 16:54:13 UTC
+++ src/MEDLoader/MeshFormatReader.hxx
@@ -35,7 +35,7 @@
 
 #include <fstream>
 
-#if !defined(WIN32) && !defined(__APPLE__)
+#if !defined(WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <features.h>
 #endif
 
