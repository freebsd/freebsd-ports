--- third_party/swiftshader/third_party/llvm-7.0/configs/linux/include/llvm/Config/config.h.orig	2019-04-30 22:26:00 UTC
+++ third_party/swiftshader/third_party/llvm-7.0/configs/linux/include/llvm/Config/config.h
@@ -8,15 +8,15 @@
 #define BUG_REPORT_URL "https://bugs.llvm.org/"
 
 /* Define to 1 to enable backtraces, and to 0 otherwise. */
-/* #undef ENABLE_BACKTRACES */
+#define ENABLE_BACKTRACES 1
 
 /* Define to 1 to enable crash overrides, and to 0 otherwise. */
-/* #undef ENABLE_CRASH_OVERRIDES */
+#define ENABLE_CRASH_OVERRIDES 1
 
 /* Define to 1 if you have the `backtrace' function. */
-/* #undef HAVE_BACKTRACE */
+#define HAVE_BACKTRACE TRUE
 
-/* #undef BACKTRACE_HEADER */
+#define BACKTRACE_HEADER <execinfo.h>
 
 /* Define to 1 if you have the <CrashReporterClient.h> header file. */
 /* #undef HAVE_CRASHREPORTERCLIENT_H */
@@ -26,7 +26,7 @@
 
 /* Define to 1 if you have the declaration of `arc4random', and to 0 if you
    don't. */
-#define HAVE_DECL_ARC4RANDOM 0
+#define HAVE_DECL_ARC4RANDOM 1
 
 /* Define to 1 if you have the declaration of `FE_ALL_EXCEPT', and to 0 if you
    don't. */
@@ -50,7 +50,7 @@
 #define HAVE_DLOPEN 1
 
 /* Define if dladdr() is available on this platform. */
-/* #undef HAVE_DLADDR */
+#define HAVE_DLADDR 1
 
 /* Define to 1 if you have the <errno.h> header file. */
 #define HAVE_ERRNO_H 1
@@ -89,7 +89,7 @@
 #define HAVE_ISATTY 1
 
 /* Define to 1 if you have the `edit' library (-ledit). */
-/* #undef HAVE_LIBEDIT */
+#define HAVE_LIBEDIT 1
 
 /* Define to 1 if you have the `pfm' library (-lpfm). */
 /* #undef HAVE_LIBPFM */
@@ -107,25 +107,25 @@
 /* #undef HAVE_PTHREAD_SETNAME_NP */
 
 /* Define to 1 if you have the `z' library (-lz). */
-/* #undef HAVE_LIBZ */
+#define HAVE_LIBZ 1
 
 /* Define to 1 if you have the <link.h> header file. */
 #define HAVE_LINK_H 1
 
 /* Define to 1 if you have the `lseek64' function. */
-#define HAVE_LSEEK64 1
+/* #undef HAVE_LSEEK64 */
 
 /* Define to 1 if you have the <mach/mach.h> header file. */
 /* #undef HAVE_MACH_MACH_H */
 
 /* Define to 1 if you have the `mallctl' function. */
-/* #undef HAVE_MALLCTL */
+#define HAVE_MALLCTL 1
 
 /* Define to 1 if you have the `mallinfo' function. */
-#define HAVE_MALLINFO 1
+/* #undef HAVE_MALLINFO */
 
 /* Define to 1 if you have the <malloc.h> header file. */
-#define HAVE_MALLOC_H 1
+/* #undef HAVE_MALLOC_H */
 
 /* Define to 1 if you have the <malloc/malloc.h> header file. */
 /* #undef HAVE_MALLOC_MALLOC_H */
@@ -137,7 +137,7 @@
 #define HAVE_POSIX_FALLOCATE 1
 
 /* Define to 1 if you have the `posix_spawn' function. */
-/* #undef HAVE_POSIX_SPAWN */
+#define HAVE_POSIX_SPAWN 1
 
 /* Define to 1 if you have the `pread' function. */
 #define HAVE_PREAD 1
@@ -158,16 +158,16 @@
 #define HAVE_REALPATH 1
 
 /* Define to 1 if you have the `sbrk' function. */
-#define HAVE_SBRK 1
+/* #undef HAVE_SBRK */
 
 /* Define to 1 if you have the `setenv' function. */
 #define HAVE_SETENV 1
 
 /* Define to 1 if you have the `sched_getaffinity' function. */
-#define HAVE_SCHED_GETAFFINITY 1
+/* #undef HAVE_SCHED_GETAFFINITY */
 
 /* Define to 1 if you have the `CPU_COUNT' macro. */
-#define HAVE_CPU_COUNT 1
+/* #undef HAVE_CPU_COUNT */
 
 /* Define to 1 if you have the `setrlimit' function. */
 #define HAVE_SETRLIMIT 1
@@ -209,13 +209,13 @@
 #define HAVE_SYS_TYPES_H 1
 
 /* Define if the setupterm() function is supported this platform. */
-/* #undef HAVE_TERMINFO */
+#define HAVE_TERMINFO 1
 
 /* Define if the xar_open() function is supported this platform. */
 /* #undef HAVE_LIBXAR */
 
 /* Define to 1 if you have the <termios.h> header file. */
-/* #undef HAVE_TERMIOS_H */
+#define HAVE_TERMIOS_H 1
 
 /* Define to 1 if you have the <unistd.h> header file. */
 #define HAVE_UNISTD_H 1
@@ -224,7 +224,7 @@
 /* #undef HAVE_VALGRIND_VALGRIND_H */
 
 /* Define to 1 if you have the <zlib.h> header file. */
-/* #undef HAVE_ZLIB_H */
+#define HAVE_ZLIB_H 1
 
 /* Have host's _alloca */
 /* #undef HAVE__ALLOCA */
@@ -298,7 +298,7 @@
 #elif defined(__arm__)
 #define LLVM_DEFAULT_TARGET_TRIPLE "armv7-linux-gnueabihf"
 #elif defined(__aarch64__)
-#define LLVM_DEFAULT_TARGET_TRIPLE "aarch64-linux-gnu"
+#define LLVM_DEFAULT_TARGET_TRIPLE "aarch64-portbld-freebsd"
 #elif defined(__mips__)
 #define LLVM_DEFAULT_TARGET_TRIPLE "mipsel-linux-gnu"
 #elif defined(__mips64)
@@ -308,7 +308,7 @@
 #endif
 
 /* Define if zlib compression is available */
-#define LLVM_ENABLE_ZLIB 0
+#define LLVM_ENABLE_ZLIB 1
 
 /* Define if overriding target triple is enabled */
 /* #undef LLVM_TARGET_TRIPLE_ENV */
