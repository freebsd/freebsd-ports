--- third_party/swiftshader/src/OpenGL/libEGL/libEGL.hpp.orig	2018-12-15 16:38:54.529408000 +0100
+++ third_party/swiftshader/src/OpenGL/libEGL/libEGL.hpp	2018-12-15 16:39:22.143716000 +0100
@@ -100,7 +100,7 @@
 				#endif
 			#elif defined(__ANDROID__)
 				const char *libEGL_lib[] = {"libEGL_swiftshader.so", "libEGL_swiftshader.so"};
-			#elif defined(__linux__)
+			#elif defined(__linux__) || defined(__FreeBSD__)
 				#if defined(__LP64__)
 					const char *libEGL_lib[] = {"lib64EGL_translator.so", "libEGL.so.1", "libEGL.so"};
 				#else
