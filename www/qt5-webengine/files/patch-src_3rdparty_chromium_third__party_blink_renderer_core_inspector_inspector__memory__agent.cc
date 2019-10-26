--- src/3rdparty/chromium/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc
@@ -171,7 +171,7 @@ InspectorMemoryAgent::GetSamplingProfileById(uint32_t 
 
 std::vector<std::string> InspectorMemoryAgent::Symbolize(
     const std::vector<void*>& addresses) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // TODO(alph): Move symbolization to the client.
   std::vector<void*> addresses_to_symbolize;
   for (void* address : addresses) {
