--- src/3rdparty/chromium/third_party/pdfium/fxjs/js_define.cpp.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/pdfium/fxjs/js_define.cpp
@@ -19,18 +19,23 @@
 namespace {
 
 double GetLocalTZA() {
+  struct tm *lt;
   if (!FSDK_IsSandBoxPolicyEnabled(FPDF_POLICY_MACHINETIME_ACCESS))
     return 0;
   time_t t = 0;
   time(&t);
-  localtime(&t);
+  lt = localtime(&t);
 #if _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
   // In gcc 'timezone' is a global variable declared in time.h. In VC++, that
   // variable was removed in VC++ 2015, with _get_timezone replacing it.
   long timezone = 0;
   _get_timezone(&timezone);
 #endif  // _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
+#if defined(__FreeBSD__)
+  return (double)(-(lt->tm_gmtoff * 1000));
+#else
   return (double)(-(timezone * 1000));
+#endif
 }
 
 int GetDaylightSavingTA(double d) {
