This allows building on amd64 and with gcc above 3.x. Adding support for
other architectures is easy too.

	-mi

--- tnlTypes.h.orig	2004-09-28 18:45:25 UTC
+++ tnlTypes.h
@@ -284,8 +284,8 @@ typedef unsigned long long  U64;  ///< Compiler indepe
 // Identify the target CPU and assembly language options
 //----------------------------------------------------------------------------------
 
-#if defined(_M_IX86) || defined(i386)
-#  define TNL_CPU_STRING "Intel x86"
+#if defined(_M_IX86) || defined(i386) || defined(__amd64__)
+#  define TNL_CPU_STRING "x86"
 #  define TNL_CPU_X86
 #  define TNL_LITTLE_ENDIAN
 #  define TNL_SUPPORTS_NASM
@@ -293,7 +293,7 @@ typedef unsigned long long  U64;  ///< Compiler indepe
 #  if defined (__GNUC__)
 #    if __GNUC__ == 2
 #      define TNL_GCC_2
-#    elif __GNUC__ == 3
+#    elif __GNUC__ >= 3
 #      define TNL_GCC_3
 #    else
 #      error "TNL: Unsupported version of GCC (see tnlMethodDispatch.cpp)"
