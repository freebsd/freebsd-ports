--- parttypes.h.orig	2022-04-14 23:17:12 UTC
+++ parttypes.h
@@ -15,6 +15,10 @@
 #define UnicodeString std::string
 #endif
 
+#ifdef USE_UTF16
+using namespace icu;
+#endif
+
 // A partition type
 struct AType {
    // I'm using a custom 16-bit extension of the original MBR 8-bit
