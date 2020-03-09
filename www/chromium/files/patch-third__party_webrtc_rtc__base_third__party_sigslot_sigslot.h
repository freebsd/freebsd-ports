--- third_party/webrtc/rtc_base/third_party/sigslot/sigslot.h.orig	2020-03-03 18:55:31 UTC
+++ third_party/webrtc/rtc_base/third_party/sigslot/sigslot.h
@@ -178,6 +178,8 @@ class multi_threaded_local {
 #endif  // _SIGSLOT_HAS_WIN32_THREADS
 
 #ifdef _SIGSLOT_HAS_POSIX_THREADS
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
 // The multi threading policies only get compiled in if they are enabled.
 class multi_threaded_global {
  public:
@@ -201,6 +203,7 @@ class multi_threaded_local {
  private:
   pthread_mutex_t m_mutex;
 };
+#pragma GCC diagnostic pop
 #endif  // _SIGSLOT_HAS_POSIX_THREADS
 
 template <class mt_policy>
