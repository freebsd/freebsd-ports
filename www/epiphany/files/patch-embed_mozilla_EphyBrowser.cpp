--- embed/mozilla/EphyBrowser.cpp.orig	Sat May 15 12:20:12 2004
+++ embed/mozilla/EphyBrowser.cpp	Sun Jul 18 19:12:01 2004
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
@@ -574,7 +576,7 @@
 	return NS_OK;
 }
 
-nsresult EphyBrowser::GetSHUrlAtIndex (PRInt32 index, nsCString &url)
+nsresult EphyBrowser::GetSHUrlAtIndex (PRInt32 index, nsACString &url)
 {
 	NS_ENSURE_TRUE (mWebBrowser, NS_ERROR_FAILURE);
 
@@ -642,7 +644,7 @@
 	return NS_OK;
 }
 
-nsresult EphyBrowser::GetDocumentUrl (nsCString &url)
+nsresult EphyBrowser::GetDocumentUrl (nsACString &url)
 {
 	NS_ENSURE_TRUE (mDOMWindow, NS_ERROR_FAILURE);
 
@@ -668,7 +670,7 @@
 	return uri->GetSpec (url);
 }
 
-nsresult EphyBrowser::GetTargetDocumentUrl (nsCString &url)
+nsresult EphyBrowser::GetTargetDocumentUrl (nsACString &url)
 {
 	NS_ENSURE_TRUE (mWebBrowser, NS_ERROR_FAILURE);
 
