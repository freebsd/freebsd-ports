--- src/mozilla/GaleonWrapper.cpp.orig	Thu Jan  2 13:55:14 2003
+++ src/mozilla/GaleonWrapper.cpp	Thu Jan  2 13:56:16 2003
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
 
