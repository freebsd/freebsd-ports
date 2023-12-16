--- src/3rdparty/chromium/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc.orig	2022-06-17 14:20:10 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc
@@ -190,7 +190,7 @@ InspectorMemoryAgent::GetSamplingProfileById(uint32_t 
 
 Vector<String> InspectorMemoryAgent::Symbolize(
     const WebVector<void*>& addresses) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(alph): Move symbolization to the client.
   Vector<void*> addresses_to_symbolize;
   for (size_t i = 0; i < addresses.size(); i++) {
