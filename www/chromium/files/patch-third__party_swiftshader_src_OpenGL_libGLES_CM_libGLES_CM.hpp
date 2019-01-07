--- third_party/swiftshader/src/OpenGL/libGLES_CM/libGLES_CM.hpp.orig	2018-12-03 21:20:24.000000000 +0100
+++ third_party/swiftshader/src/OpenGL/libGLES_CM/libGLES_CM.hpp	2018-12-15 16:45:47.909334000 +0100
@@ -261,7 +261,7 @@
 				#endif
 			#elif defined(__ANDROID__)
 				const char *libGLES_CM_lib[] = {"libGLESv1_CM_swiftshader.so", "libGLESv1_CM_swiftshader.so"};
-			#elif defined(__linux__)
+			#elif defined(__linux__) || defined(__FreeBSD__)
 				#if defined(__LP64__)
 					const char *libGLES_CM_lib[] = {"lib64GLES_CM_translator.so", "libGLES_CM.so.1", "libGLES_CM.so"};
 				#else
