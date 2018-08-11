--- glm/simd/platform.h.orig	2018-08-09 13:49:02 UTC
+++ glm/simd/platform.h
@@ -77,58 +77,37 @@
 
 // Intel
 #define GLM_COMPILER_INTEL			0x00100000
-#define GLM_COMPILER_INTEL12		0x00100010
-#define GLM_COMPILER_INTEL12_1		0x00100020
-#define GLM_COMPILER_INTEL13		0x00100030
 #define GLM_COMPILER_INTEL14		0x00100040
 #define GLM_COMPILER_INTEL15		0x00100050
 #define GLM_COMPILER_INTEL16		0x00100060
+#define GLM_COMPILER_INTEL17		0x00100070
 
 // Visual C++ defines
 #define GLM_COMPILER_VC				0x01000000
-#define GLM_COMPILER_VC10			0x01000090
-#define GLM_COMPILER_VC11			0x010000A0
 #define GLM_COMPILER_VC12			0x010000B0
 #define GLM_COMPILER_VC14			0x010000C0
 #define GLM_COMPILER_VC15			0x010000D0
+#define GLM_COMPILER_VC16			0x010000E0
 
 // GCC defines
 #define GLM_COMPILER_GCC			0x02000000
-#define GLM_COMPILER_GCC44			0x020000B0
-#define GLM_COMPILER_GCC45			0x020000C0
 #define GLM_COMPILER_GCC46			0x020000D0
 #define GLM_COMPILER_GCC47			0x020000E0
 #define GLM_COMPILER_GCC48			0x020000F0
 #define GLM_COMPILER_GCC49			0x02000100
-#define GLM_COMPILER_GCC50			0x02000200
-#define GLM_COMPILER_GCC51			0x02000300
-#define GLM_COMPILER_GCC52			0x02000400
-#define GLM_COMPILER_GCC53			0x02000500
-#define GLM_COMPILER_GCC54			0x02000600
-#define GLM_COMPILER_GCC60			0x02000700
-#define GLM_COMPILER_GCC61			0x02000800
-#define GLM_COMPILER_GCC62			0x02000900
-#define GLM_COMPILER_GCC70			0x02000A00
-#define GLM_COMPILER_GCC71			0x02000B00
-#define GLM_COMPILER_GCC72			0x02000C00
-#define GLM_COMPILER_GCC80			0x02000D00
+#define GLM_COMPILER_GCC5			0x02000200
+#define GLM_COMPILER_GCC6			0x02000300
+#define GLM_COMPILER_GCC7			0x02000400
+#define GLM_COMPILER_GCC8			0x02000500
 
 // CUDA
 #define GLM_COMPILER_CUDA			0x10000000
-#define GLM_COMPILER_CUDA40			0x10000040
-#define GLM_COMPILER_CUDA41			0x10000050
-#define GLM_COMPILER_CUDA42			0x10000060
-#define GLM_COMPILER_CUDA50			0x10000070
-#define GLM_COMPILER_CUDA60			0x10000080
-#define GLM_COMPILER_CUDA65			0x10000090
 #define GLM_COMPILER_CUDA70			0x100000A0
 #define GLM_COMPILER_CUDA75			0x100000B0
 #define GLM_COMPILER_CUDA80			0x100000C0
 
 // Clang
 #define GLM_COMPILER_CLANG			0x20000000
-#define GLM_COMPILER_CLANG32		0x20000030
-#define GLM_COMPILER_CLANG33		0x20000040
 #define GLM_COMPILER_CLANG34		0x20000050
 #define GLM_COMPILER_CLANG35		0x20000060
 #define GLM_COMPILER_CLANG36		0x20000070
@@ -148,20 +127,16 @@
 #	define GLM_COMPILER GLM_COMPILER_UNKNOWN
 
 #elif defined(__INTEL_COMPILER)
-#	if __INTEL_COMPILER == 1200
-#		define GLM_COMPILER GLM_COMPILER_INTEL12
-#	elif __INTEL_COMPILER == 1210
-#		define GLM_COMPILER GLM_COMPILER_INTEL12_1
-#	elif __INTEL_COMPILER == 1300
-#		define GLM_COMPILER GLM_COMPILER_INTEL13
+#	if (__clang_major__ < 1400)
+#		error "GLM requires ICC 2013 SP1 or newer"
 #	elif __INTEL_COMPILER == 1400
 #		define GLM_COMPILER GLM_COMPILER_INTEL14
 #	elif __INTEL_COMPILER == 1500
 #		define GLM_COMPILER GLM_COMPILER_INTEL15
-#	elif __INTEL_COMPILER >= 1600
+#	elif __INTEL_COMPILER == 1600
 #		define GLM_COMPILER GLM_COMPILER_INTEL16
-#	else
-#		define GLM_COMPILER GLM_COMPILER_INTEL
+#	elif __INTEL_COMPILER >= 1700
+#		define GLM_COMPILER GLM_COMPILER_INTEL17
 #	endif
 
 // CUDA
@@ -169,37 +144,27 @@
 #	if !defined(CUDA_VERSION) && !defined(GLM_FORCE_CUDA)
 #		include <cuda.h>  // make sure version is defined since nvcc does not define it itself!
 #	endif
-#	if CUDA_VERSION < 3000
-#		error "GLM requires CUDA 3.0 or higher"
+#	if CUDA_VERSION < 7000
+#		error "GLM requires CUDA 7.0 or higher"
 #	else
 #		define GLM_COMPILER GLM_COMPILER_CUDA
 #	endif
 
 // Clang
 #elif defined(__clang__)
-#	if defined(__apple_build_version__)
-#		if __clang_major__ == 5 && __clang_minor__ == 0
-#			define GLM_COMPILER GLM_COMPILER_CLANG33
-#		elif __clang_major__ == 5 && __clang_minor__ == 1
-#			define GLM_COMPILER GLM_COMPILER_CLANG34
+#	if GLM_PLATFORM & GLM_PLATFORM_APPLE
+#		if (__clang_major__ < 6)
+#			error "GLM requires Clang 3.4 / Apple Clang 6.0 or higher"
 #		elif __clang_major__ == 6 && __clang_minor__ == 0
 #			define GLM_COMPILER GLM_COMPILER_CLANG35
 #		elif __clang_major__ == 6 && __clang_minor__ >= 1
 #			define GLM_COMPILER GLM_COMPILER_CLANG36
 #		elif __clang_major__ >= 7
 #			define GLM_COMPILER GLM_COMPILER_CLANG37
-#		else
-#			define GLM_COMPILER GLM_COMPILER_CLANG
 #		endif
 #	else
-#		if __clang_major__ == 3 && __clang_minor__ == 0
-#			define GLM_COMPILER GLM_COMPILER_CLANG30
-#		elif __clang_major__ == 3 && __clang_minor__ == 1
-#			define GLM_COMPILER GLM_COMPILER_CLANG31
-#		elif __clang_major__ == 3 && __clang_minor__ == 2
-#			define GLM_COMPILER GLM_COMPILER_CLANG32
-#		elif __clang_major__ == 3 && __clang_minor__ == 3
-#			define GLM_COMPILER GLM_COMPILER_CLANG33
+#		if ((__clang_major__ == 3) && (__clang_minor__ < 4)) || (__clang_major__ < 3)
+#			error "GLM requires Clang 3.4 or higher"
 #		elif __clang_major__ == 3 && __clang_minor__ == 4
 #			define GLM_COMPILER GLM_COMPILER_CLANG34
 #		elif __clang_major__ == 3 && __clang_minor__ == 5
@@ -220,39 +185,25 @@
 #			define GLM_COMPILER GLM_COMPILER_CLANG42
 #		elif __clang_major__ >= 4
 #			define GLM_COMPILER GLM_COMPILER_CLANG42
-#		else
-#			define GLM_COMPILER GLM_COMPILER_CLANG
 #		endif
 #	endif
 
 // Visual C++
 #elif defined(_MSC_VER)
-#	if _MSC_VER < 1600
-#		error "GLM requires Visual C++ 10 - 2010 or higher"
-#	elif _MSC_VER == 1600
-#		define GLM_COMPILER GLM_COMPILER_VC11
-#	elif _MSC_VER == 1700
-#		define GLM_COMPILER GLM_COMPILER_VC11
+#	if _MSC_VER < 1800
+#		error "GLM requires Visual C++ 12 - 2013 or higher"
 #	elif _MSC_VER == 1800
 #		define GLM_COMPILER GLM_COMPILER_VC12
 #	elif _MSC_VER == 1900
 #		define GLM_COMPILER GLM_COMPILER_VC14
 #	elif _MSC_VER >= 1910
 #		define GLM_COMPILER GLM_COMPILER_VC15
-#	else//_MSC_VER
-#		define GLM_COMPILER GLM_COMPILER_VC
 #	endif//_MSC_VER
 
 // G++
 #elif defined(__GNUC__) || defined(__MINGW32__)
-#	if (__GNUC__ == 4) && (__GNUC_MINOR__ == 2)
-#		define GLM_COMPILER (GLM_COMPILER_GCC42)
-#	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 3)
-#		define GLM_COMPILER (GLM_COMPILER_GCC43)
-#	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 4)
-#		define GLM_COMPILER (GLM_COMPILER_GCC44)
-#	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 5)
-#		define GLM_COMPILER (GLM_COMPILER_GCC45)
+#	if ((__GNUC__ == 4) && (__GNUC_MINOR__ < 6)) || (__GNUC__ < 4)
+#		error "GLM requires GCC 4.7 or higher"
 #	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 6)
 #		define GLM_COMPILER (GLM_COMPILER_GCC46)
 #	elif (__GNUC__ == 4) && (__GNUC_MINOR__ == 7)
@@ -261,32 +212,14 @@
 #		define GLM_COMPILER (GLM_COMPILER_GCC48)
 #	elif (__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)
 #		define GLM_COMPILER (GLM_COMPILER_GCC49)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ == 0)
-#		define GLM_COMPILER (GLM_COMPILER_GCC50)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ == 1)
-#		define GLM_COMPILER (GLM_COMPILER_GCC51)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ == 2)
-#		define GLM_COMPILER (GLM_COMPILER_GCC52)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ == 3)
-#		define GLM_COMPILER (GLM_COMPILER_GCC53)
-#	elif (__GNUC__ == 5) && (__GNUC_MINOR__ >= 4)
-#		define GLM_COMPILER (GLM_COMPILER_GCC54)
-#	elif (__GNUC__ == 6) && (__GNUC_MINOR__ == 0)
-#		define GLM_COMPILER (GLM_COMPILER_GCC60)
-#	elif (__GNUC__ == 6) && (__GNUC_MINOR__ == 1)
-#		define GLM_COMPILER (GLM_COMPILER_GCC61)
-#	elif (__GNUC__ == 6) && (__GNUC_MINOR__ >= 2)
-#		define GLM_COMPILER (GLM_COMPILER_GCC62)
-#	elif (__GNUC__ == 7) && (__GNUC_MINOR__ == 0)
-#		define GLM_COMPILER (GLM_COMPILER_GCC70)
-#	elif (__GNUC__ == 7) && (__GNUC_MINOR__ == 1)
-#		define GLM_COMPILER (GLM_COMPILER_GCC71)
-#	elif (__GNUC__ == 7) && (__GNUC_MINOR__ == 2)
-#		define GLM_COMPILER (GLM_COMPILER_GCC72)
+#	elif (__GNUC__ == 5)
+#		define GLM_COMPILER (GLM_COMPILER_GCC5)
+#	elif (__GNUC__ == 6)
+#		define GLM_COMPILER (GLM_COMPILER_GCC6)
+#	elif (__GNUC__ == 7)
+#		define GLM_COMPILER (GLM_COMPILER_GCC7)
 #	elif (__GNUC__ >= 8)
-#		define GLM_COMPILER (GLM_COMPILER_GCC80)
-#	else
-#		define GLM_COMPILER (GLM_COMPILER_GCC)
+#		define GLM_COMPILER (GLM_COMPILER_GCC8)
 #	endif
 
 #else
