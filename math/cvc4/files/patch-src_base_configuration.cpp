--- src/base/configuration.cpp.orig	2018-06-25 21:13:17 UTC
+++ src/base/configuration.cpp
@@ -405,7 +405,7 @@ std::string Configuration::getCompiler() {
 }
 
 std::string Configuration::getCompiledDateTime() {
-  return __DATE__ " " __TIME__;
+  return "(timestamp removed for reproducible builds)";
 }
 
 }/* CVC4 namespace */
