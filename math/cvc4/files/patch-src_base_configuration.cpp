--- src/base/configuration.cpp.orig	2018-04-22 17:53:43 UTC
+++ src/base/configuration.cpp
@@ -291,7 +291,7 @@ std::string Configuration::getCompiler() {
 }
 
 std::string Configuration::getCompiledDateTime() {
-  return __DATE__ " " __TIME__;
+  return "(timestamp removed for reproducible builds)";
 }
 
 }/* CVC4 namespace */
