--- src/mozilla/GaleonWrapper.cpp.orig	Fri Apr 11 17:57:19 2003
+++ src/mozilla/GaleonWrapper.cpp	Fri May 16 17:52:46 2003
@@ -70,7 +70,11 @@
 #include "nsIDocumentObserver.h"
 #include "nsCWebBrowser.h"
 #include "nsReadableUtils.h"
+#if MOZILLA_SNAPSHOT > 7
+#include "nsIDOMNSDocument.h"
+#else
 #include "nsIDOMNSHTMLDocument.h"
+#endif
 #include "nsIDOMHTMLDocument.h"
 #include "nsIDOMHTMLCollection.h"
 #include "nsIDOMHTMLElement.h"
@@ -1290,7 +1294,11 @@
 	result = GetDOMDocument (getter_AddRefs(aDOMDocument));
 	if (NS_FAILED(result) || !aDOMDocument) return NS_ERROR_FAILURE;
 
+#if MOZILLA_SNAPSHOT > 7
+	nsCOMPtr<nsIDOMNSDocument> doc = do_QueryInterface(aDOMDocument);
+#else
 	nsCOMPtr<nsIDOMNSHTMLDocument> doc = do_QueryInterface(aDOMDocument);
+#endif
 	if(!doc) return NS_ERROR_FAILURE;
 
 	nsAutoString value;
