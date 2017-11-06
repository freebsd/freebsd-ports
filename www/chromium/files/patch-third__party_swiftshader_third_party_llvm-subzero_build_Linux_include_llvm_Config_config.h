--- third_party/swiftshader/third_party/llvm-subzero/build/Linux/include/llvm/Config/config.h.orig	2017-06-26 22:28:18.140795000 +0200
+++ third_party/swiftshader/third_party/llvm-subzero/build/Linux/include/llvm/Config/config.h	2017-06-26 22:30:40.465311000 +0200
@@ -121,7 +121,7 @@
 #define HAVE_LINK_H 1
 
 /* Define to 1 if you have the `lseek64' function. */
-#define HAVE_LSEEK64 1
+/* #undef HAVE_LSEEK64 */
 
 /* Define to 1 if you have the <mach/mach.h> header file. */
 /* #undef HAVE_MACH_MACH_H */
@@ -130,7 +130,7 @@
 /* #undef HAVE_MALLCTL */
 
 /* Define to 1 if you have the `mallinfo' function. */
-#define HAVE_MALLINFO 1
+/* #undef HAVE_MALLINFO */
 
 /* Define to 1 if you have the <malloc.h> header file. */
 #define HAVE_MALLOC_H 1
@@ -154,7 +154,7 @@
 /* #undef HAVE_NDIR_H */
 
 /* Define to 1 if you have the `posix_fallocate' function. */
-#define HAVE_POSIX_FALLOCATE 1
+/* #undef HAVE_POSIX_FALLOCATE */
 
 /* Define to 1 if you have the `posix_spawn' function. */
 #define HAVE_POSIX_SPAWN 1
