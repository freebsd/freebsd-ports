--- embed/mozilla/EphyBrowser.cpp.orig	Wed Jul  7 15:41:04 2004
+++ embed/mozilla/EphyBrowser.cpp	Wed Jul  7 15:47:03 2004
@@ -249,11 +249,13 @@
 	nsCOMPtr<nsPIDOMWindow> piWin(do_QueryInterface(domWindow));
 	NS_ENSURE_TRUE (piWin, NS_ERROR_FAILURE);
 
+#if MOZILLA_SNAPSHOT < 18
   	nsCOMPtr<nsIChromeEventHandler> chromeHandler;
   	piWin->GetChromeEventHandler(getter_AddRefs(chromeHandler));
 
   	mEventReceiver = do_QueryInterface(chromeHandler);
 	NS_ENSURE_TRUE (mEventReceiver, NS_ERROR_FAILURE);
+#endif
 
 	return NS_OK;
 }
