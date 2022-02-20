--- third_party/swiftshader/src/Common/Configurator.cpp.orig	2022-02-07 13:39:41 UTC
+++ third_party/swiftshader/src/Common/Configurator.cpp
@@ -42,6 +42,10 @@ namespace sw
 
 	bool Configurator::readFile()
 	{
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+		return false;
+#endif
+
 		#if defined(__unix__)
 			if(access(path.c_str(), R_OK) != 0)
 			{
