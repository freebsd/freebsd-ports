--- dom/src/threads/nsDOMWorker.h.orig	2012-03-06 15:45:25.000000000 +0100
+++ dom/src/threads/nsDOMWorker.h	2012-10-28 01:42:16.000000000 +0200
@@ -74,7 +74,7 @@ class nsDOMWorkerScope : public nsDOMWor
 {
   friend class nsDOMWorker;
 
-  typedef nsresult (NS_STDCALL nsDOMWorkerScope::*SetListenerFunc)
+  typedef nsresult (NS_DEFCALL nsDOMWorkerScope::*SetListenerFunc)
     (nsIDOMEventListener*);
 
 public:
