--- include/ogdf/internal/basic/config.h.orig	2015-05-29 15:36:28 UTC
+++ include/ogdf/internal/basic/config.h
@@ -95,6 +95,11 @@ using std::string;
 #define OGDF_SYSTEM_OSX
 #endif
 
+// Note: FreeBSD machines will be both OGDF_SYSTEM_UNIX and OGDF_SYSTEM_OSX
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define OGDF_SYSTEM_FREEBSD
+#endif
+
 
 // COIN and ABACUS
 #if defined(USE_COIN)
@@ -124,7 +129,7 @@ using std::string;
 // C++ standard
 //---------------------------------------------------------
 
-#if __cplusplus >= 201103
+#if __cplusplus >= 201103L
 #define OGDF_HAVE_CPP11
 
 #elif defined(_MSC_VER)
