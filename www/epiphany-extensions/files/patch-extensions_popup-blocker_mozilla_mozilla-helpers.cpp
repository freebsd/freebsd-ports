--- extensions/popup-blocker/mozilla/mozilla-helpers.cpp.orig	Mon Mar 15 17:07:05 2004
+++ extensions/popup-blocker/mozilla/mozilla-helpers.cpp	Mon Jul 19 20:33:33 2004
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
@@ -181,7 +185,11 @@
 	g_free (script);
 
 	PRBool isUndefined;
+#if MOZILLA_SNAPSHOT < 18
 	nsAutoString ret;
+#else
+	nsAString *ret;
+#endif
 	context->EvaluateString (aScript, nsnull, nsnull, nsnull, 0,
 				 nsnull, ret, &isUndefined);
 
