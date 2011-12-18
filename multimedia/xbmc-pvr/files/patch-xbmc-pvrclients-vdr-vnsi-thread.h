--- xbmc/pvrclients/vdr-vnsi/thread.h.orig
+++ xbmc/pvrclients/vdr-vnsi/thread.h
@@ -76,7 +76,11 @@ public:
   void Unlock(void);
   };
 
+#ifdef __FreeBSD__
+typedef pthread_t tThreadId;
+#else
 typedef pid_t tThreadId;
+#endif
 
 class cThread {
   friend class cThreadLock;
@@ -123,7 +127,7 @@ public:
   bool Active(void);
        ///< Checks whether the thread is still alive.
   static tThreadId ThreadId(void);
-  static tThreadId IsMainThread(void) { return ThreadId() == mainThreadId; }
+  static int IsMainThread(void) { return ThreadId() == mainThreadId; }
   static void SetMainThreadId(void);
   };
 
