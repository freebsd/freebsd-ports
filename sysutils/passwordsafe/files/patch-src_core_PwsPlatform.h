--- src/core/PwsPlatform.h.orig	2019-03-26 09:46:50 UTC
+++ src/core/PwsPlatform.h
@@ -140,6 +140,8 @@
 #define LTC_NO_ROLC
 #if defined(__i386__) || defined(__amd64__)
 #define PWS_LITTLE_ENDIAN
+#elif defined(__ppc__)
+#define PWS_BIG_ENDIAN
 #endif
 // **********************************************
 // * Add other platforms here...                *
