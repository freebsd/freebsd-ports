--- src/core/Backend.cpp.orig	2026-01-04 07:23:45 UTC
+++ src/core/Backend.cpp
@@ -24,6 +24,10 @@
 #include <print>
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
+
 using namespace Hyprtoolkit;
 using namespace Hyprutils::Memory;
 
@@ -416,7 +420,12 @@ void CBackend::enterLoop() {
 
     m_sLoopState.event = true; // let it process once
 
-    m_sLoopState.eventLoopThreadID = gettid();
+    m_sLoopState.eventLoopThreadID =
+#if defined(__linux__)
+        gettid();
+#elif defined(__FreeBSD__)
+        pthread_getthreadid_np();
+#endif
 
     while (!m_terminate) {
         std::unique_lock lk(m_sLoopState.eventRequestMutex);
