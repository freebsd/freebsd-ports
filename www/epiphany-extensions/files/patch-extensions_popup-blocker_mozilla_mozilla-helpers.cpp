--- extensions/popup-blocker/mozilla/mozilla-helpers.cpp.orig	Wed Jul  7 15:55:52 2004
+++ extensions/popup-blocker/mozilla/mozilla-helpers.cpp	Wed Jul  7 15:57:58 2004
@@ -65,12 +65,16 @@
 	nsCOMPtr<nsPIDOMWindow> piWin(do_QueryInterface (domWindow, &rv));
 	NS_ENSURE_SUCCESS (rv, NULL);
 
+#if MOZILLA_SNAPSHOT < 18
 	nsCOMPtr<nsIChromeEventHandler> chromeHandler;
 	rv = piWin->GetChromeEventHandler (getter_AddRefs (chromeHandler));
 	NS_ENSURE_SUCCESS (rv, NULL);
+#endif
 
 	nsCOMPtr<nsIDOMEventReceiver> eventReceiver;
+#if MOZILLA_SNAPSHOT < 18
 	eventReceiver = do_QueryInterface (chromeHandler, &rv);
+#endif
 	NS_ENSURE_SUCCESS (rv, NULL);
 
 	nsCOMPtr<nsIDOMEventTarget> target;
