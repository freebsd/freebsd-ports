--- src/3rdparty/chromium/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc
@@ -186,7 +186,7 @@ Vector<String> InspectorMemoryAgent::Symbolize(
 
 Vector<String> InspectorMemoryAgent::Symbolize(
     const WebVector<void*>& addresses) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(alph): Move symbolization to the client.
   Vector<void*> addresses_to_symbolize;
   for (size_t i = 0; i < addresses.size(); i++) {
