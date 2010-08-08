--- module/embed/gecko/kz-mozwrapper.cpp	(revision 3871)
+++ module/embed/gecko/kz-mozwrapper.cpp	(revision 3872)
@@ -102,7 +102,7 @@
 #ifndef G_OS_WIN32
 #  define nsString_h___
 #  define nsAString_h___
-#  include <nsPresContext.h>
+//#  include <nsPresContext.h>
 #  undef nsAString_h___
 #  undef nsString_h___
 #endif
@@ -2152,29 +2152,5 @@
 gboolean
 KzMozWrapper::SetZoomOnDocShell (float aZoom, nsIDocShell *DocShell)
 {
-#ifndef G_OS_WIN32
-	nsCOMPtr<nsPresContext> PresContext;
-	nsresult rv = DocShell->GetPresContext (getter_AddRefs(PresContext));
-	if (NS_FAILED(rv) || !PresContext) return FALSE;
-
-	nsIDeviceContext *DeviceContext(nsnull);
-	DeviceContext = PresContext->DeviceContext();
-	if (!DeviceContext) return FALSE;
-
-	nsCOMPtr<nsIContentViewer> ContentViewer;
-	
-	rv = DocShell->GetContentViewer(getter_AddRefs(ContentViewer));
-	if (NS_FAILED(rv) || !ContentViewer) return FALSE;
-
-	nsCOMPtr<nsIMarkupDocumentViewer> mdv = do_QueryInterface(ContentViewer);
-	if (!mdv) return FALSE;
-
-	rv = mdv->SetTextZoom (aZoom);
-
-	if NS_FAILED(rv) return FALSE;
-	
-	return TRUE;
-#else
-	return FALSE;
-#endif
+	return NS_SUCCEEDED(mDOMWindow->SetTextZoom(aZoom));
 }
