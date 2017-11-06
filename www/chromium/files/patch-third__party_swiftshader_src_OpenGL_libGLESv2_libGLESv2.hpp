--- third_party/swiftshader/src/OpenGL/libGLESv2/libGLESv2.hpp.orig	2017-06-26 22:26:03.983772000 +0200
+++ third_party/swiftshader/src/OpenGL/libGLESv2/libGLESv2.hpp	2017-06-26 22:26:31.197604000 +0200
@@ -290,7 +290,7 @@
 				#else
 					const char *libGLESv2_lib[] = {"/vendor/lib/egl/libGLESv2_swiftshader.so"};
 				#endif
-			#elif defined(__linux__)
+			#elif defined(__linux__) || defined(__FreeBSD__)
 				#if defined(__LP64__)
 					const char *libGLESv2_lib[] = {"lib64GLES_V2_translator.so", "libGLESv2.so.2", "libGLESv2.so"};
 				#else
