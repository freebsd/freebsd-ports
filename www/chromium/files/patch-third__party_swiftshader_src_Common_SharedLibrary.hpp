--- third_party/swiftshader/src/Common/SharedLibrary.hpp.orig	2017-06-26 22:08:50.265243000 +0200
+++ third_party/swiftshader/src/Common/SharedLibrary.hpp	2017-06-26 22:10:22.637465000 +0200
@@ -92,7 +92,7 @@
 
 	inline void *getLibraryHandle(const char *path)
 	{
-		#ifdef __ANDROID__
+		#if defined( __ANDROID__) || defined(__FreeBSD__)
 			// bionic doesn't support RTLD_NOLOAD before L
 			return dlopen(path, RTLD_NOW | RTLD_LOCAL);
 		#else
