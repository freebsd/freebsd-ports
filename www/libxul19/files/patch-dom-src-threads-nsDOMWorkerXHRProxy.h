--- dom/src/threads/nsDOMWorkerXHRProxy.h.orig	2012-10-28 01:49:37.000000000 +0200
+++ dom/src/threads/nsDOMWorkerXHRProxy.h	2012-10-28 01:49:45.000000000 +0200
@@ -74,7 +74,7 @@ class nsDOMWorkerXHRProxy : public nsIRu
   friend class nsDOMWorkerXHR;
   friend class nsDOMWorkerXHRUpload;
 
-  typedef nsresult (NS_STDCALL nsIDOMEventTarget::*EventListenerFunction)
+  typedef nsresult (NS_DEFCALL nsIDOMEventTarget::*EventListenerFunction)
     (const nsAString&, nsIDOMEventListener*, PRBool);
 
 public:
