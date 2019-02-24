--- third_party/swiftshader/src/OpenGL/libEGL/Display.cpp.orig	2019-01-12 22:59:44.902034000 +0100
+++ third_party/swiftshader/src/OpenGL/libEGL/Display.cpp	2019-01-12 23:00:33.372667000 +0100
@@ -684,7 +684,7 @@
 			return status != 0;
 		}
 		return false;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__)
 		return false;  // Non X11 linux is headless only
 	#elif defined(__APPLE__)
 		return sw::OSX::IsValidWindow(window);
@@ -860,7 +860,7 @@
 		{
 			return sw::FORMAT_X8R8G8B8;
 		}
-	#elif defined(__linux__)  // Non X11 linux is headless only
+	#elif defined(__linux__) || defined(__FreeBSD__) // Non X11 linux is headless only
 		return sw::FORMAT_A8B8G8R8;
 	#elif defined(__APPLE__)
 		return sw::FORMAT_A8B8G8R8;
