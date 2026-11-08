--- modules/core/includes/getos.h.orig	2026-05-19 09:32:07 UTC
+++ modules/core/includes/getos.h
@@ -27,10 +27,14 @@
 #ifdef __linux__
 #define OSNAME "linux"
 #else
+#ifdef __FreeBSD__
+#define OSNAME "freebsd"
+#else
 #ifdef _MSC_VER
 #define OSNAME "windows"
 #else
 #define OSNAME "other"
+#endif
 #endif
 #endif
 #endif
