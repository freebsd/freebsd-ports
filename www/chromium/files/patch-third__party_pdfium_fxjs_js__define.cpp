--- third_party/pdfium/fxjs/js_define.cpp.orig	2018-12-15 15:47:24.332696000 +0100
+++ third_party/pdfium/fxjs/js_define.cpp	2018-12-15 15:47:30.435519000 +0100
@@ -24,6 +24,11 @@
     return 0;
   time_t t = 0;
   FXSYS_time(&t);
+#ifdef __FreeBSD__
+  struct tm lt;
+  localtime_r(&t, &lt);
+  return (double)(-(lt.tm_gmtoff * 1000));
+#else
   localtime(&t);
 #if _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
   // In gcc 'timezone' is a global variable declared in time.h. In VC++, that
@@ -32,6 +37,7 @@
   _get_timezone(&timezone);
 #endif  // _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
   return (double)(-(timezone * 1000));
+#endif // __FreeBSD__
 }
 
 int GetDaylightSavingTA(double d) {
