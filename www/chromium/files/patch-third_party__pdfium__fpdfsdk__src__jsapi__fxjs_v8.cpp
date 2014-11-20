--- third_party/pdfium/fpdfsdk/src/jsapi/fxjs_v8.cpp.orig	2014-10-10 09:15:55 UTC
+++ third_party/pdfium/fpdfsdk/src/jsapi/fxjs_v8.cpp
@@ -753,12 +753,17 @@
 
 double _getLocalTZA()
 {
+	struct tm *lt;
 	if(!FSDK_IsSandBoxPolicyEnabled(FPDF_POLICY_MACHINETIME_ACCESS))
 		return 0;
 	time_t t = 0;
 	time(&t);
-	localtime(&t);
+	lt = localtime(&t);
+#ifdef __FreeBSD__
+	return (double)(-(lt->tm_gmtoff * 1000));
+#else
 	return (double)(-(timezone * 1000));
+#endif
 }
 
 int _getDaylightSavingTA(double d)
