--- base/stdpre.h.orig	2018-03-21 08:48:06 UTC
+++ base/stdpre.h
@@ -94,7 +94,8 @@
 #endif
 
 /* restrict is standard in C99, but not in all C++ compilers. */
-#if __STDC_VERSION__ == 199901L /* C99 */
+#if __STDC_VERSION__ >= 199901L /* C99 */
+#define gs_restrict restrict
 #elif defined(_MSC_VER) && _MSC_VER >= 1500 /* MSVC 9 or newer */
 #define gs_restrict __restrict
 #elif __GNUC__ >= 3 /* GCC 3 or newer */
