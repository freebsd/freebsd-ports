--- third_party/pdfium/fpdfsdk/src/javascript/PublicMethods.cpp.orig	2014-10-02 17:40:24 UTC
+++ third_party/pdfium/fpdfsdk/src/javascript/PublicMethods.cpp
@@ -1052,7 +1052,7 @@
 //function AFNumber_Format(nDec, sepStyle, negStyle, currStyle, strCurrency, bCurrencyPrepend)
 FX_BOOL CJS_PublicMethods::AFNumber_Format(OBJ_METHOD_PARAMS)
 {
-#if _FX_OS_ != _FX_ANDROID_
+#if _FX_OS_ != _FX_ANDROID_ && _FX_OS_ != _FX_LINUX_DESKTOP_
 	v8::Isolate* isolate = ::GetIsolate(cc);
 	CJS_Context* pContext = (CJS_Context *)cc;
 	ASSERT(pContext != NULL);
@@ -1393,7 +1393,7 @@
 //function AFPercent_Format(nDec, sepStyle)
 FX_BOOL CJS_PublicMethods::AFPercent_Format(OBJ_METHOD_PARAMS)
 {
-#if _FX_OS_ != _FX_ANDROID_
+#if _FX_OS_ != _FX_ANDROID_ && _FX_OS_ != _FX_LINUX_DESKTOP_
 	CJS_Context* pContext = (CJS_Context *)cc;
 	ASSERT(pContext != NULL);
 	CJS_EventHandler* pEvent = pContext->GetEventHandler();
