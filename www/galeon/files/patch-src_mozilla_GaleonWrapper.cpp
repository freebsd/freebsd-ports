--- src/mozilla/GaleonWrapper.cpp.orig	Fri Oct 25 20:52:28 2002
+++ src/mozilla/GaleonWrapper.cpp	Thu Feb  6 15:36:06 2003
@@ -80,8 +80,10 @@
 #include "caps/nsIPrincipal.h"
 #include "nsIDeviceContext.h"
 #include "nsIPresContext.h"
+#if MOZILLA_SNAPSHOT > 2
 #include "nsITypeAheadFind.h"
 #include "nsSupportsPrimitives.h"
+#endif
 
 GaleonWrapper::GaleonWrapper ()
 {
@@ -584,6 +586,7 @@
 			      PRBool search_in_frames,
 			      PRBool *didFind)
 {
+#if MOZILLA_SNAPSHOT > 2
 	if (!interactive)
 	{
 		nsresult rv;
@@ -610,6 +613,7 @@
 			}
 		}
 	}
+#endif
 
 	nsCOMPtr<nsIWebBrowserFind> finder (do_GetInterface(mWebBrowser));
 
@@ -984,7 +988,6 @@
 					       nsIStyleSheet **return_sheet)
 {
 	nsresult result;
-	PRBool completed;
 
 	/* catch necessary stuff */
 	nsCOMPtr<nsIDocShell> DocShell;
@@ -1014,7 +1017,12 @@
 	if (NS_FAILED(result)) return NS_ERROR_FAILURE;
 
 	nsICSSStyleSheet *sheet;
+#if MOZILLA_SNAPSHOT > 3
+	result = loader->LoadAgentSheet(uri, &sheet);
+#else
+	PRBool completed;
 	result = loader->LoadAgentSheet(uri, sheet, completed, nsnull);
+#endif
 	if (NS_FAILED(result)) return NS_ERROR_FAILURE;
 
 	/* catch stylesheet stuff and apply by appending it as a override
