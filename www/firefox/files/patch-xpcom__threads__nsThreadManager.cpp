--- ./xpcom/threads/nsThreadManager.cpp.orig	2011-08-25 02:37:45.000000000 +0200
+++ ./xpcom/threads/nsThreadManager.cpp	2011-08-28 17:14:14.000000000 +0200
@@ -89,6 +89,10 @@
 nsresult
 nsThreadManager::Init()
 {
+#ifdef NS_TLS
+  if (!gTLSThreadID)
+    gTLSThreadID = mozilla::threads::Generic;
+#endif
   if (!mThreadsByPRThread.Init())
     return NS_ERROR_OUT_OF_MEMORY;
 
