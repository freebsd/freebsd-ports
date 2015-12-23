--- ./third_party/pdfium/fpdfsdk/src/javascript/JS_Value.cpp.orig	2015-12-04 23:43:52.716604000 +0100
+++ ./third_party/pdfium/fpdfsdk/src/javascript/JS_Value.cpp	2015-12-04 23:45:17.502470000 +0100
@@ -586,11 +586,12 @@
 }
 
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
@@ -598,7 +599,11 @@
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
