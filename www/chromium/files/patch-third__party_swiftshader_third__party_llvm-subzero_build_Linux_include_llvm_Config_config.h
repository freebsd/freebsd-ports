--- third_party/swiftshader/third_party/llvm-subzero/build/Linux/include/llvm/Config/config.h.orig	2021-09-24 04:28:17 UTC
+++ third_party/swiftshader/third_party/llvm-subzero/build/Linux/include/llvm/Config/config.h
@@ -5,7 +5,9 @@
 #include "llvm/Config/llvm-config.h"
 
 /* For detecting __GLIBC__ usage */
+#ifndef __FreeBSD__
 #include <features.h>
+#endif
 
 /* Bug report URL. */
 #define BUG_REPORT_URL "http://llvm.org/bugs/"
@@ -124,7 +126,7 @@
 #define HAVE_LINK_H 1
 
 /* Define to 1 if you have the `lseek64' function. */
-#define HAVE_LSEEK64 1
+/* #undef HAVE_LSEEK64 */
 
 /* Define to 1 if you have the <mach/mach.h> header file. */
 /* #undef HAVE_MACH_MACH_H */
@@ -133,7 +135,7 @@
 /* #undef HAVE_MALLCTL */
 
 /* Define to 1 if you have the `mallinfo' function. */
-#define HAVE_MALLINFO 1
+/* #undef HAVE_MALLINFO */
 
 /* Some projects using SwiftShader bypass cmake (eg Chromium via gn) */
 /* so we need to check glibc version for the new API to be safe */
@@ -163,7 +165,7 @@
 /* #undef HAVE_NDIR_H */
 
 /* Define to 1 if you have the `posix_fallocate' function. */
-#define HAVE_POSIX_FALLOCATE 1
+/* #undef HAVE_POSIX_FALLOCATE */
 
 /* Define to 1 if you have the `posix_spawn' function. */
 #define HAVE_POSIX_SPAWN 1
