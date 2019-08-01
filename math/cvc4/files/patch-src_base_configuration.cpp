--- src/base/configuration.cpp.orig	2019-04-09 16:14:31 UTC
+++ src/base/configuration.cpp
@@ -376,7 +376,7 @@ std::string Configuration::getCompiler() {
 }
 
 std::string Configuration::getCompiledDateTime() {
-  return __DATE__ " " __TIME__;
+  return "(timestamp removed for reproducible builds)";
 }
 
 }/* CVC4 namespace */
