--- embed/mozilla/EphyBrowser.h.orig	Sun Dec 19 02:17:33 2004
+++ embed/mozilla/EphyBrowser.h	Sun Dec 19 02:17:56 2004
@@ -156,11 +156,13 @@
 	nsCOMPtr<nsIDOMDocument> mTargetDocument;
 	nsCOMPtr<nsIDOMEventTarget> mEventTarget;
 	nsCOMPtr<nsIDOMWindow> mDOMWindow;
-	nsCOMPtr<nsISecureBrowserUI> mSecurityInfo;
 	EphyFaviconEventListener *mFaviconEventListener;
 	EphyPopupBlockEventListener *mPopupBlockEventListener;
 	EphyModalAlertEventListener *mModalAlertListener;
 	PRBool mInitialized;
+#ifdef HAVE_MOZILLA_PSM
+	nsCOMPtr<nsISecureBrowserUI> mSecurityInfo;
+#endif
 
 	nsresult GetListener (void);
 	nsresult AttachListeners (void);
