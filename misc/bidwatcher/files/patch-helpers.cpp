$FreeBSD$

--- helpers.cpp.orig	Sat Oct 30 15:02:55 2004
+++ helpers.cpp	Sat Oct 30 15:05:25 2004
@@ -121,7 +121,11 @@
 bool strToFloat(const char *str, float &x)
 {
   char *end = 0;
+#if defined(__FreeBSD__) && __FreeBSD__ < 5
+  x = (float) strtod(str, &end);
+#else
   x = strtof(str, &end);
+#endif
   return end != str && *end == 0;
 }
 
