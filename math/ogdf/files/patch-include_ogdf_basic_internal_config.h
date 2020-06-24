--- include/ogdf/basic/internal/config.h.orig	2015-05-29 15:36:28 UTC
+++ include/ogdf/basic/internal/config.h
@@ -95,6 +95,11 @@ using std::string;
 #define OGDF_SYSTEM_OSX
 #endif
 
+// Note: FreeBSD machines will be both OGDF_SYSTEM_UNIX and OGDF_SYSTEM_OSX
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define OGDF_SYSTEM_FREEBSD
+#endif
+
 
 // C++11 standard
 
