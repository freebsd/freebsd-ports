--- core/Apple/IWork.cpp.orig	2025-03-08 16:26:16.590289000 +0100
+++ core/Apple/IWork.cpp	2025-03-08 16:45:14.932729000 +0100
@@ -6,7 +6,8 @@
 #include <libodfgen/OdtGenerator.hxx>
 #include <libodfgen/OdsGenerator.hxx>
 #include <libodfgen/OdpGenerator.hxx>
-#include <libodfgen/test/StringDocumentHandler.hxx>
+//#include <libodfgen/test/StringDocumentHandler.hxx>
+#include "StringDocumentHandler.hxx"
 
 #include <memory>
 #include <fstream>
