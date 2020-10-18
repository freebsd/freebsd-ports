--- deps/git/OpenCL-Headers/CL/cl_platform.h.orig	2020-10-18 01:01:11 UTC
+++ deps/git/OpenCL-Headers/CL/cl_platform.h
@@ -431,7 +431,9 @@ typedef unsigned int cl_GLenum;
 
 /* Define basic vector types */
 #if defined( __VEC__ )
+# ifndef __clang__
    #include <altivec.h>   /* may be omitted depending on compiler. AltiVec spec provides no way to detect whether the header is required. */
+# endif
    typedef vector unsigned char     __cl_uchar16;
    typedef vector signed char       __cl_char16;
    typedef vector unsigned short    __cl_ushort8;
