--- third_party/pdfium/fpdfsdk/javascript/JS_Value.cpp.orig	2017-04-19 19:07:50 UTC
+++ third_party/pdfium/fpdfsdk/javascript/JS_Value.cpp
@@ -457,11 +457,12 @@ v8::Local<v8::Date> CJS_Date::ToV8Date(C
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
@@ -469,7 +470,11 @@ double _getLocalTZA() {
   long timezone = 0;
   _get_timezone(&timezone);
 #endif
+#if defined(__FreeBSD__)
+  return (double)(-(lt->tm_gmtoff * 1000));
+#else
   return (double)(-(timezone * 1000));
+#endif
 }
 
 int _getDaylightSavingTA(double d) {
