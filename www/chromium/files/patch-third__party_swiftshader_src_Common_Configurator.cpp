--- third_party/swiftshader/src/Common/Configurator.cpp.orig	2018-07-19 21:20:56.462917000 +0200
+++ third_party/swiftshader/src/Common/Configurator.cpp	2018-07-19 21:23:09.940292000 +0200
@@ -42,6 +42,9 @@
 
 	bool Configurator::readFile()
 	{
+#if defined(__FreeBSD__)
+                return false;
+#endif      
 		#if defined(__unix__)
 			if(access(path.c_str(), R_OK) != 0)
 			{
