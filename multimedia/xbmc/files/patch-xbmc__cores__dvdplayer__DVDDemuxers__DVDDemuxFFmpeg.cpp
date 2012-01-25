--- ./xbmc/cores/dvdplayer/DVDDemuxers/DVDDemuxFFmpeg.cpp.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/cores/dvdplayer/DVDDemuxers/DVDDemuxFFmpeg.cpp	2012-01-02 10:14:38.000000000 +0100
@@ -91,12 +91,20 @@
 
 CCriticalSection DllAvCodec::m_critSection;
 static CCriticalSection m_logSection;
+#ifdef __FreeBSD__
+std::map<uint64_t, CStdString> g_logbuffer;
+#else
 std::map<uintptr_t, CStdString> g_logbuffer;
+#endif
 
 void ff_avutil_log(void* ptr, int level, const char* format, va_list va)
 {
   CSingleLock lock(m_logSection);
+#ifdef __FreeBSD__
+  uint64_t threadId = (uint64_t)CThread::GetCurrentThreadId();
+#else
   uintptr_t threadId = (uintptr_t)CThread::GetCurrentThreadId();
+#endif
   CStdString &buffer = g_logbuffer[threadId];
 
   AVClass* avc= ptr ? *(AVClass**)ptr : NULL;
@@ -145,7 +153,11 @@
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
