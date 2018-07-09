--- modules/config/base.hh.orig	2018-07-09 01:41:40 UTC
+++ modules/config/base.hh
@@ -56,22 +56,26 @@ typedef unsigned short Word;
 #ifndef round_function
 #define round_function
 #ifndef round
+#if !defined(__FreeBSD__)
 inline Real round( Real d )
 {
   return floor(d+Real(0.5));
 }
 #endif
 #endif
+#endif
 
 #ifndef rint_function
 #define rint_function
 #ifndef rint
+#if !defined(__FreeBSD__)
 inline Real rint(Real d)
 {
   return floor(d+Real(0.5));
 }
 #endif
 #endif
+#endif
 
 #if _MSC_VER
 #pragma warning(disable:4251)
