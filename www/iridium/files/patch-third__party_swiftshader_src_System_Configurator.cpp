--- third_party/swiftshader/src/System/Configurator.cpp.orig	2025-12-10 15:04:57 UTC
+++ third_party/swiftshader/src/System/Configurator.cpp
@@ -38,6 +38,9 @@ namespace sw {
 
 Configurator::Configurator(const std::string &filePath)
 {
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+	return;
+#endif
 	std::fstream file(filePath, std::ios::in);
 	if(file.fail())
 	{
