--- lib/libXDAAP/threadpool.c.orig
+++ lib/libXDAAP/threadpool.c
@@ -279,10 +279,10 @@
 void CP_ThreadPool_QueueWorkItem(CP_SThreadPool *pTPThis, CP_TPfnJob pfnCallback,
                                  void *arg1, void *arg2)
 {
-    ts_mutex_lock(pTPThis->mtJobQueueMutex);
-
     CP_STPJobQueue *pTPJQNewJob = malloc(sizeof(CP_STPJobQueue));
 
+    ts_mutex_lock(pTPThis->mtJobQueueMutex);
+
     pTPJQNewJob->fnJobCallback = pfnCallback;
     pTPJQNewJob->arg1 = arg1;
     pTPJQNewJob->arg2 = arg2;
