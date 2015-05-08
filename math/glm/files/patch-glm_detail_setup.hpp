--- glm/detail/setup.hpp.orig	2015-05-07 21:31:27 UTC
+++ glm/detail/setup.hpp
@@ -62,6 +62,7 @@
 #define GLM_PLATFORM_UNIX			0x00400000
 #define GLM_PLATFORM_QNXNTO			0x00800000
 #define GLM_PLATFORM_WINCE			0x01000000
+#define GLM_PLATFORM_FREEBSD		0x02000000
 
 #ifdef GLM_FORCE_PLATFORM_UNKNOWN
 #	define GLM_PLATFORM GLM_PLATFORM_UNKNOWN
@@ -79,6 +80,8 @@
 #	define GLM_PLATFORM GLM_PLATFORM_ANDROID
 #elif defined(__linux)
 #	define GLM_PLATFORM GLM_PLATFORM_LINUX
+#elif defined(__FreeBSD__)
+#	define GLM_PLATFORM GLM_PLATFORM_FREEBSD
 #elif defined(__unix)
 #	define GLM_PLATFORM GLM_PLATFORM_UNIX
 #else
@@ -104,6 +107,8 @@
 #		pragma message("GLM: Android platform detected")
 #	elif(GLM_PLATFORM & GLM_PLATFORM_LINUX)
 #		pragma message("GLM: Linux platform detected")
+#	elif(GLM_PLATFORM & GLM_PLATFORM_FREEBSD)
+#		pragma message("GLM: FreeBSD platform detected")
 #	elif(GLM_PLATFORM & GLM_PLATFORM_UNIX)
 #		pragma message("GLM: UNIX platform detected")
 #	elif(GLM_PLATFORM & GLM_PLATFORM_UNKNOWN)
@@ -523,7 +528,11 @@
 
 // N1988
 #if GLM_LANG & GLM_LANG_CXX11_FLAG
-#	define GLM_HAS_EXTENDED_INTEGER_TYPE 1
+#	if (GLM_PLATFORM & GLM_PLATFORM_FREEBSD) && (GLM_COMPILER & GLM_COMPILER_LLVM)
+#		define GLM_HAS_EXTENDED_INTEGER_TYPE __has_include(<__config>)
+#   else
+#		define GLM_HAS_EXTENDED_INTEGER_TYPE 1
+#	endif
 #else
 #	define GLM_HAS_EXTENDED_INTEGER_TYPE (\
 		((GLM_LANG & GLM_LANG_CXX0X_FLAG) && (GLM_COMPILER & GLM_COMPILER_VC) && (GLM_COMPILER >= GLM_COMPILER_VC2012)) || \
@@ -638,7 +647,11 @@
 
 // 
 #if GLM_LANG & GLM_LANG_CXX11_FLAG
-#	define GLM_HAS_MAKE_SIGNED 1
+#	if (GLM_PLATFORM & GLM_PLATFORM_FREEBSD) && (GLM_COMPILER & GLM_COMPILER_LLVM)
+#		define GLM_HAS_MAKE_SIGNED __has_include(<__config>)
+#	else
+#		define GLM_HAS_MAKE_SIGNED 1
+#	endif
 #else
 #	define GLM_HAS_MAKE_SIGNED (GLM_LANG & GLM_LANG_CXX0X_FLAG) && (\
 		((GLM_COMPILER & GLM_COMPILER_VC) && (GLM_COMPILER >= GLM_COMPILER_VC2013)))
