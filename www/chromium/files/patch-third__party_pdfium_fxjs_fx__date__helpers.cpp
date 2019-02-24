--- third_party/pdfium/fxjs/fx_date_helpers.cpp.orig	2019-02-01 12:43:47.112647000 +0100
+++ third_party/pdfium/fxjs/fx_date_helpers.cpp	2019-02-01 12:49:38.012493000 +0100
@@ -34,6 +34,11 @@
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
@@ -42,6 +47,7 @@
   _get_timezone(&timezone);
 #endif  // _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
   return (double)(-(timezone * 1000));
+#endif // __FreeBSD__
 }
 
 int GetDaylightSavingTA(double d) {
