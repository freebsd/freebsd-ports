--- ./xpcom/threads/nsThreadManager.cpp.orig	2011-08-25 02:37:45.000000000 +0200
+++ ./xpcom/threads/nsThreadManager.cpp	2011-08-28 17:14:14.000000000 +0200
@@ -57,6 +57,11 @@
 nsresult
 nsThreadManager::Init()
 {
+#if defined(NS_TLS) && (__FreeBSD_version < 802513 \
+  || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900045))
+  if (!gTLSThreadID)
+    gTLSThreadID = mozilla::threads::Generic;
+#endif
   mThreadsByPRThread.Init();
 
   if (PR_NewThreadPrivateIndex(&mCurThreadIndex, ReleaseObject) == PR_FAILURE)
