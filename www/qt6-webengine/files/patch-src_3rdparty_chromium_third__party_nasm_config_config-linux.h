--- src/3rdparty/chromium/third_party/nasm/config/config-linux.h.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/third_party/nasm/config/config-linux.h
@@ -160,7 +160,7 @@
 
 /* Define to 1 if you have the declaration of `strlcpy', and to 0 if you
    don't. */
-#define HAVE_DECL_STRLCPY 0
+#define HAVE_DECL_STRLCPY 1
 
 /* Define to 1 if you have the declaration of `strncasecmp', and to 0 if you
    don't. */
@@ -183,7 +183,7 @@
 #define HAVE_DECL_STRSEP 1
 
 /* Define to 1 if you have the <endian.h> header file. */
-#define HAVE_ENDIAN_H 1
+/* #undef HAVE_ENDIAN_H */
 
 /* Define to 1 if you have the `faccessat' function. */
 #define HAVE_FACCESSAT 1
@@ -327,16 +327,16 @@
 #define HAVE_ISASCII 1
 
 /* Define to 1 if you have the `iscntrl' function. */
-/* #undef HAVE_ISCNTRL */
+#define HAVE_ISCNTRL 1
 
 /* Define to 1 if you have the <machine/endian.h> header file. */
-/* #undef HAVE_MACHINE_ENDIAN_H */
+#define HAVE_MACHINE_ENDIAN_H 1
 
 /* Define to 1 if you have the <memory.h> header file. */
 #define HAVE_MEMORY_H 1
 
 /* Define to 1 if you have the `mempcpy' function. */
-#define HAVE_MEMPCPY 1
+/* #undef HAVE_MEMPCPY */
 
 /* Define to 1 if you have a working `mmap' system call. */
 #define HAVE_MMAP 1
@@ -357,7 +357,7 @@
 #define HAVE_STDARG_H 1
 
 /* Define to 1 if stdbool.h conforms to C99. */
-/* #undef HAVE_STDBOOL_H */
+#define HAVE_STDBOOL_H 1
 
 /* Define to 1 if your compiler supports C99 extern inline */
 #define HAVE_STDC_INLINE 1
@@ -384,7 +384,7 @@
 #define HAVE_STRING_H 1
 
 /* Define to 1 if you have the `strlcpy' function. */
-/* #undef HAVE_STRLCPY */
+#define HAVE_STRLCPY 1
 
 /* Define to 1 if you have the `strncasecmp' function. */
 #define HAVE_STRNCASECMP 1
@@ -411,7 +411,7 @@
 #define HAVE_SYSCONF 1
 
 /* Define to 1 if you have the <sys/endian.h> header file. */
-/* #undef HAVE_SYS_ENDIAN_H */
+#define HAVE_SYS_ENDIAN_H 1
 
 /* Define to 1 if you have the <sys/mman.h> header file. */
 #define HAVE_SYS_MMAN_H 1
@@ -486,13 +486,13 @@
 /* #undef HAVE__STATI64 */
 
 /* Define to 1 if you have the `__bswap_16' intrinsic function. */
-#define HAVE___BSWAP_16 1
+/* #undef HAVE___BSWAP_16 */
 
 /* Define to 1 if you have the `__bswap_32' intrinsic function. */
-#define HAVE___BSWAP_32 1
+/* #undef HAVE___BSWAP_32 */
 
 /* Define to 1 if you have the `__bswap_64' intrinsic function. */
-#define HAVE___BSWAP_64 1
+/* #undef HAVE___BSWAP_64 */
 
 /* Define to 1 if you have the `__builtin_bswap16' intrinsic function. */
 #define HAVE___BUILTIN_BSWAP16 1
@@ -620,7 +620,7 @@
 /* Define to the equivalent of the C99 'restrict' keyword, or to
    nothing if this is not supported.  Do not define if restrict is
    supported directly.  */
-#define restrict __restrict
+#define restrict __restrict__
 /* Work around a bug in Sun C++: it does not support _Restrict or
    __restrict__, even though the corresponding Sun C compiler ends up with
    "#define restrict _Restrict" or "#define restrict __restrict__" in the
@@ -637,7 +637,7 @@
 /* Define if your snprintf function is not named snprintf. */
 /* #undef snprintf */
 
-/* Define if your typeof operator is not named typeof. */
+/* Define if your typeof operator is not named `typeof'. */
 #define typeof __typeof
 
 /* Define to the type of an unsigned integer type wide enough to hold a
