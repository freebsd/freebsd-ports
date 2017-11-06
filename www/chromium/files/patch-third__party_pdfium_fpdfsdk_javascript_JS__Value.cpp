--- third_party/pdfium/fpdfsdk/javascript/JS_Value.cpp.orig	2017-09-05 21:06:52.000000000 +0200
+++ third_party/pdfium/fpdfsdk/javascript/JS_Value.cpp	2017-09-07 00:04:22.552844000 +0200
@@ -44,7 +44,12 @@
   long timezone = 0;
   _get_timezone(&timezone);
 #endif
+#ifdef __FreeBSD__
+  struct tm *lt;
+  return (double)(-(lt->tm_gmtoff * 1000));
+#else
   return (double)(-(timezone * 1000));
+#endif
 }
 
 int GetDaylightSavingTA(double d) {
