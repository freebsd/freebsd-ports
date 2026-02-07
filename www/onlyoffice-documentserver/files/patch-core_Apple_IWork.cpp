--- core/Apple/IWork.cpp.orig	2025-08-02 18:33:34 UTC
+++ core/Apple/IWork.cpp
@@ -6,7 +6,8 @@
 #include <libodfgen/OdtGenerator.hxx>
 #include <libodfgen/OdsGenerator.hxx>
 #include <libodfgen/OdpGenerator.hxx>
-#include <libodfgen/test/StringDocumentHandler.hxx>
+//#include <libodfgen/test/StringDocumentHandler.hxx>
+#include "StringDocumentHandler.hxx"
 
 #include <memory>
 #include <fstream>
