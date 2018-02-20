--- third_party/pdfium/fpdfsdk/javascript/JS_Value.cpp.orig	2017-12-15 02:05:39.000000000 +0100
+++ third_party/pdfium/fpdfsdk/javascript/JS_Value.cpp	2017-12-24 18:51:32.588224000 +0100
@@ -37,7 +37,12 @@
   long timezone = 0;
   _get_timezone(&timezone);
 #endif  // _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
+#ifdef __FreeBSD__
+  struct tm *lt;
+  return (double)(-(lt->tm_gmtoff * 1000));
+#else
   return (double)(-(timezone * 1000));
+#endif
 }
 
 int GetDaylightSavingTA(double d) {
