--- third_party/pdfium/fpdfsdk/src/jsapi/fxjs_v8.cpp.orig	2015-10-14 18:34:09.173122000 +0200
+++ third_party/pdfium/fpdfsdk/src/jsapi/fxjs_v8.cpp	2015-10-14 18:36:12.927162000 +0200
@@ -908,11 +908,12 @@
 // JavaScript time implement begin.
 
 double _getLocalTZA() {
+  struct tm *lt;
   if (!FSDK_IsSandBoxPolicyEnabled(FPDF_POLICY_MACHINETIME_ACCESS))
     return 0;
   time_t t = 0;
   time(&t);
-  localtime(&t);
+  lt = localtime(&t);
 #if _MSC_VER >= 1900
   // In gcc and in Visual Studio prior to VS 2015 'timezone' is a global
   // variable declared in time.h. That variable was deprecated and in VS 2015
@@ -920,7 +921,11 @@
   long timezone = 0;
   _get_timezone(&timezone);
 #endif
+#ifdef __FreeBSD__
+  return (double)(-(lt->tm_gmtoff * 1000));
+#else
   return (double)(-(timezone * 1000));
+#endif
 }
 
 int _getDaylightSavingTA(double d) {
