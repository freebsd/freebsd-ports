--- cef/libcef/browser/context.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/context.cc
@@ -363,7 +363,7 @@ bool CefContext::Initialize(const CefMai
   settings_ = settings;
   application_ = application;
 
-#if !(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX))
+#if !(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   if (settings.multi_threaded_message_loop) {
     NOTIMPLEMENTED() << "multi_threaded_message_loop is not supported.";
     return false;
