--- src/StringTokenizer.cc.orig	Mon Jul 14 08:15:49 2003
+++ src/StringTokenizer.cc	Mon Jul 14 08:18:44 2003
@@ -34,6 +34,14 @@
 #include "MathMLAttribute.hh"
 #include "StringTokenizer.hh"
 
+#ifdef __FreeBSD__
+#if (__FreeBSD_version < 500000)
+#define iswxdigit isxdigit
+#define towupper toupper
+#define iswdigit isdigit
+#endif
+#endif
+
 static unsigned hexOfChar(Char ch)
 {
   assert(iswxdigit(ch));
