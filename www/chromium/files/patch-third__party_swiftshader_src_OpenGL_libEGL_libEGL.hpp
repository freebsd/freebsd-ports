--- third_party/swiftshader/src/OpenGL/libEGL/libEGL.hpp.orig	2017-06-26 22:22:21.418803000 +0200
+++ third_party/swiftshader/src/OpenGL/libEGL/libEGL.hpp	2017-06-26 22:22:37.089147000 +0200
@@ -106,7 +106,7 @@
 				#else
 					const char *libEGL_lib[] = {"/vendor/lib/egl/libEGL_swiftshader.so"};
 				#endif
-			#elif defined(__linux__)
+			#elif defined(__linux__) || defined(__FreeBSD__)
 				#if defined(__LP64__)
 					const char *libEGL_lib[] = {"lib64EGL_translator.so", "libEGL.so.1", "libEGL.so"};
 				#else
