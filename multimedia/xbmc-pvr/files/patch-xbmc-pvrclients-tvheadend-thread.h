--- xbmc/pvrclients/tvheadend/thread.h.orig
+++ xbmc/pvrclients/tvheadend/thread.h
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
@@ -127,7 +131,7 @@ public:
   bool Active(void);
        ///< Checks whether the thread is still alive.
   static tThreadId ThreadId(void);
-  static tThreadId IsMainThread(void) { return ThreadId() == mainThreadId; }
+  static int IsMainThread(void) { return ThreadId() == mainThreadId; }
   static void SetMainThreadId(void);
   };
 
