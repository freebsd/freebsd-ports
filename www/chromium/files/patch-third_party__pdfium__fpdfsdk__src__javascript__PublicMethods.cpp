--- third_party/pdfium/fpdfsdk/src/javascript/PublicMethods.cpp.orig	2015-10-14 18:30:46.180316000 +0200
+++ third_party/pdfium/fpdfsdk/src/javascript/PublicMethods.cpp	2015-10-14 18:31:44.759135000 +0200
@@ -910,7 +910,7 @@
                                            const CJS_Parameters& params,
                                            CJS_Value& vRet,
                                            CFX_WideString& sError) {
-#if _FX_OS_ != _FX_ANDROID_
+#if _FX_OS_ != _FX_ANDROID_ && _FX_OS_ != _FX_LINUX_DESKTOP_
   v8::Isolate* isolate = ::GetIsolate(cc);
   CJS_Context* pContext = (CJS_Context*)cc;
   ASSERT(pContext != NULL);
@@ -1213,7 +1213,7 @@
                                             const CJS_Parameters& params,
                                             CJS_Value& vRet,
                                             CFX_WideString& sError) {
-#if _FX_OS_ != _FX_ANDROID_
+#if _FX_OS_ != _FX_ANDROID_ && _FX_OS_ != _FX_LINUX_DESKTOP_
   CJS_Context* pContext = (CJS_Context*)cc;
   ASSERT(pContext != NULL);
   CJS_EventHandler* pEvent = pContext->GetEventHandler();
