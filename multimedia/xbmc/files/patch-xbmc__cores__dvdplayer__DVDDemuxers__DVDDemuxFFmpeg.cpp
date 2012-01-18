--- ./xbmc/cores/dvdplayer/DVDDemuxers/DVDDemuxFFmpeg.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/cores/dvdplayer/DVDDemuxers/DVDDemuxFFmpeg.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -90,12 +90,20 @@
 // these need to be put somewhere that are compiled, we should have some better place for it
 
 CCriticalSection DllAvCodec::m_critSection;
+#ifdef __FreeBSD__
+std::map<uint64_t, CStdString> g_logbuffer;
+#else
 std::map<uintptr_t, CStdString> g_logbuffer;
+#endif
 
 void ff_avutil_log(void* ptr, int level, const char* format, va_list va)
 {
   CSingleLock lock(DllAvCodec::m_critSection);
+#ifdef __FreeBSD__
+  uint64_t threadId = (uint64_t)CThread::GetCurrentThreadId();
+#else
   uintptr_t threadId = (uintptr_t)CThread::GetCurrentThreadId();
+#endif
   CStdString &buffer = g_logbuffer[threadId];
 
   AVClass* avc= ptr ? *(AVClass**)ptr : NULL;
@@ -144,7 +152,11 @@
   /* Loop through the logbuffer list and remove any blank buffers
      If the thread using the buffer is still active, it will just
      add a new buffer next time it writes to the log */
+#ifdef __FreeBSD__
+  std::map<uint64_t, CStdString>::iterator it;
+#else
   std::map<uintptr_t, CStdString>::iterator it;
+#endif
   for (it = g_logbuffer.begin(); it != g_logbuffer.end(); )
     if ((*it).second.IsEmpty())
       g_logbuffer.erase(it++);
