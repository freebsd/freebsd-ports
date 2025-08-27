--- src/webrtc/src/third_party/nasm/config/config-linux.h.orig	2024-03-14 18:07:21 UTC
+++ src/webrtc/src/third_party/nasm/config/config-linux.h
@@ -209,7 +209,7 @@
 #define HAVE_DECL_STRSEP 1
 
 /* Define to 1 if you have the <endian.h> header file. */
-#define HAVE_ENDIAN_H 1
+/* #undef HAVE_ENDIAN_H */
 
 /* Define to 1 if you have the 'faccessat' function. */
 #define HAVE_FACCESSAT 1
@@ -351,10 +351,10 @@
 #define HAVE_ISASCII 1
 
 /* Define to 1 if you have the 'iscntrl' function. */
-/* #undef HAVE_ISCNTRL */
+#define HAVE_ISCNTRL 1
 
 /* Define to 1 if you have the <machine/endian.h> header file. */
-/* #undef HAVE_MACHINE_ENDIAN_H */
+#define HAVE_MACHINE_ENDIAN_H 1
 
 /* Define to 1 if you have the 'mempcpy' function. */
 #define HAVE_MEMPCPY 1
@@ -384,7 +384,7 @@
 #define HAVE_STDARG_H 1
 
 /* Define to 1 if stdbool.h conforms to C99. */
-/* #undef HAVE_STDBOOL_H */
+#define HAVE_STDBOOL_H 1
 
 /* Define to 1 if your compiler supports C99 extern inline */
 #define HAVE_STDC_INLINE 1
@@ -414,7 +414,7 @@
 #define HAVE_STRING_H 1
 
 /* Define to 1 if you have the 'strlcpy' function. */
-/* #undef HAVE_STRLCPY */ // Shouldn\'t work with -std=c11, but configure still detects it.
+#define HAVE_STRLCPY 1
 
 /* Define to 1 if you have the 'strncasecmp' function. */
 #define HAVE_STRNCASECMP 1
@@ -441,7 +441,7 @@
 #define HAVE_SYSCONF 1
 
 /* Define to 1 if you have the <sys/endian.h> header file. */
-/* #undef HAVE_SYS_ENDIAN_H */
+#define HAVE_SYS_ENDIAN_H 1
 
 /* Define to 1 if you have the <sys/mman.h> header file. */
 #define HAVE_SYS_MMAN_H 1
@@ -522,13 +522,13 @@
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
