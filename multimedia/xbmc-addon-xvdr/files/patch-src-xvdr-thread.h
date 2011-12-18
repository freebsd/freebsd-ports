--- a/src/xvdr/thread.h
+++ b/src/xvdr/thread.h
@@ -77,7 +77,11 @@ public:
   void Unlock(void);
   };
 
+#ifdef __FreeBSD__
+typedef pthread_t tThreadId;
+#else
 typedef pid_t tThreadId;
+#endif
 
 class cThread {
   friend class cThreadLock;
@@ -124,7 +128,7 @@ public:
   bool Active(void);
        ///< Checks whether the thread is still alive.
   static tThreadId ThreadId(void);
-  static tThreadId IsMainThread(void) { return ThreadId() == mainThreadId; }
+  static int IsMainThread(void) { return ThreadId() == mainThreadId; }
   static void SetMainThreadId(void);
   };
 
