--- third_party/pdfium/fpdfsdk/src/javascript/PublicMethods.cpp.orig	2016-01-21 16:45:51.849930462 +0100
+++ third_party/pdfium/fpdfsdk/src/javascript/PublicMethods.cpp	2016-01-21 16:46:22.626928815 +0100
@@ -914,7 +914,7 @@
                                            const std::vector<CJS_Value>& params,
                                            CJS_Value& vRet,
                                            CFX_WideString& sError) {
-#if _FX_OS_ != _FX_ANDROID_
+#if _FX_OS_ != _FX_ANDROID_ && _FX_OS_ != _FX_LINUX_DESKTOP_
   CJS_Context* pContext = (CJS_Context*)cc;
   if (params.size() != 6) {
     sError = JSGetStringFromID(pContext, IDS_STRING_JSPARAMERROR);
@@ -1214,7 +1214,7 @@
     const std::vector<CJS_Value>& params,
     CJS_Value& vRet,
     CFX_WideString& sError) {
-#if _FX_OS_ != _FX_ANDROID_
+#if _FX_OS_ != _FX_ANDROID_ && _FX_OS_ != _FX_LINUX_DESKTOP_
   CJS_Context* pContext = (CJS_Context*)cc;
   ASSERT(pContext != NULL);
   CJS_EventHandler* pEvent = pContext->GetEventHandler();
