--- third_party/swiftshader/src/OpenGL/libGLES_CM/libGLES_CM.hpp.orig	2017-06-26 22:23:31.609734000 +0200
+++ third_party/swiftshader/src/OpenGL/libGLES_CM/libGLES_CM.hpp	2017-06-26 22:23:56.904096000 +0200
@@ -267,7 +267,7 @@
 				#else
 					const char *libGLES_CM_lib[] = {"/vendor/lib/egl/libGLESv1_CM_swiftshader.so"};
 				#endif
-			#elif defined(__linux__)
+			#elif defined(__linux__) || defined(__FreeBSD__)
 				#if defined(__LP64__)
 					const char *libGLES_CM_lib[] = {"lib64GLES_CM_translator.so", "libGLES_CM.so.1", "libGLES_CM.so"};
 				#else
