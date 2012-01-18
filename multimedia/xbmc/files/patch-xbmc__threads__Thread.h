--- ./xbmc/threads/Thread.h.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/threads/Thread.h	2012-01-02 10:14:38.000000000 +0100
@@ -117,8 +117,12 @@
   ThreadIdentifier ThreadId() const;
   bool m_bAutoDelete;
   CEvent m_StopEvent;
+#ifdef __FreeBSD__
+  unsigned long m_ThreadId;
+#else
   unsigned m_ThreadId; // This value is unreliable on platforms using pthreads
                        // Use m_ThreadHandle->m_hThread instead
+#endif
   IRunnable* m_pRunnable;
 
   unsigned __int64 m_iLastUsage;
