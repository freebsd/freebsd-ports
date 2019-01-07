--- third_party/swiftshader/src/OpenGL/libGLESv2/libGLESv2.hpp.orig	2018-12-03 21:20:24.000000000 +0100
+++ third_party/swiftshader/src/OpenGL/libGLESv2/libGLESv2.hpp	2018-12-15 16:50:37.213988000 +0100
@@ -286,7 +286,7 @@
 				#endif
 			#elif defined(__ANDROID__)
 				const char *libGLESv2_lib[] = {"libGLESv2_swiftshader.so", "libGLESv2_swiftshader.so"};
-			#elif defined(__linux__)
+			#elif defined(__linux__) || defined(__FreeBSD__)
 				#if defined(__LP64__)
 					const char *libGLESv2_lib[] = {"lib64GLES_V2_translator.so", "libGLESv2.so.2", "libGLESv2.so"};
 				#else
