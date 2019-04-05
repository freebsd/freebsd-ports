--- third_party/pdfium/fxjs/fx_date_helpers.cpp.orig	2019-03-11 22:08:02 UTC
+++ third_party/pdfium/fxjs/fx_date_helpers.cpp
@@ -34,6 +34,11 @@ double GetLocalTZA() {
     return 0;
   time_t t = 0;
   FXSYS_time(&t);
+#ifdef __FreeBSD__
+  struct tm lt;
+  localtime_r(&t, &lt);
+  return (double)(-(lt.tm_gmtoff * 1000));
+#else
   FXSYS_localtime(&t);
 #if _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
   // In gcc 'timezone' is a global variable declared in time.h. In VC++, that
@@ -42,6 +47,7 @@ double GetLocalTZA() {
   _get_timezone(&timezone);
 #endif  // _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
   return (double)(-(timezone * 1000));
+#endif // __FreeBSD__
 }
 
 int GetDaylightSavingTA(double d) {
