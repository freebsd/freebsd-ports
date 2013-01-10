--- mozilla/content/base/src/nsTextFragmentImpl.h.orig	2013-01-05 00:44:29.000000000 +0100
+++ mozilla/content/base/src/nsTextFragmentImpl.h	2013-01-10 13:02:12.291088273 +0100
@@ -16,7 +16,11 @@
 };
 
 template<> struct Non8BitParameters<8> {
+#if !defined(__clang__) && defined(__GNUC__) && __GNUC_MINOR__ <= 2
+  static inline size_t mask() { return 0xff00ff00ff00ff00ULL; }
+#else
   static inline size_t mask() { return 0xff00ff00ff00ff00; }
+#endif
   static inline uint32_t alignMask() { return 0x7; }
   static inline uint32_t numUnicharsPerWord() { return 4; }
 };
