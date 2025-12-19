--- src/3rdparty/chromium/third_party/swiftshader/src/System/Configurator.cpp.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/swiftshader/src/System/Configurator.cpp
@@ -38,6 +38,9 @@ Configurator::Configurator(const std::string &filePath
 
 Configurator::Configurator(const std::string &filePath)
 {
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+	return;
+#endif
 	std::fstream file(filePath, std::ios::in);
 	if(file.fail())
 	{
