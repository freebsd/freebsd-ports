--- third_party/pdfium/fxjs/JS_Define.cpp.orig	2018-03-04 04:13:13.591977000 +0100
+++ third_party/pdfium/fxjs/JS_Define.cpp	2018-03-04 04:14:44.297142000 +0100
@@ -30,7 +30,12 @@
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
