--- cf-agent/verify_storage.c.orig	2016-05-03 13:42:49 UTC
+++ cf-agent/verify_storage.c
@@ -132,7 +132,7 @@ PromiseResult VerifyStoragePromise(EvalC
     PromiseResult result = PROMISE_RESULT_NOOP;
 
 #ifndef __MINGW32__
-    if ((SeqLength(GetGlobalMountedFSList())) && (!LoadMountInfo(GetGlobalMountedFSList())))
+    if ((!SeqLength(GetGlobalMountedFSList())) && (!LoadMountInfo(GetGlobalMountedFSList())))
     {
         Log(LOG_LEVEL_ERR, "Couldn't obtain a list of mounted filesystems - aborting");
         YieldCurrentLock(thislock);
