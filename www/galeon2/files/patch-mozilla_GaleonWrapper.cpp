--- mozilla/GaleonWrapper.cpp.orig	Fri May 16 17:21:37 2003
+++ mozilla/GaleonWrapper.cpp	Fri May 16 17:23:41 2003
@@ -70,7 +70,11 @@
 #include "nsCWebBrowser.h"
 #include "nsReadableUtils.h"
 #include "nsUnicharUtils.h"
+#if MOZILLA_SNAPSHOT > 7
+#include "nsIDOMNSDocument.h"
+#else
 #include "nsIDOMNSHTMLDocument.h"
+#endif
 #include "nsIDOMHTMLDocument.h"
 #include "nsIDOMHTMLCollection.h"
 #include "nsIDOMHTMLElement.h"
@@ -1106,8 +1110,13 @@
 	result = GetDOMDocument (getter_AddRefs(DOMDocument));
 	if (NS_FAILED(result) || !DOMDocument) return NS_ERROR_FAILURE;
 
+#if MOZILLA_SNAPSHOT > 7
+	nsCOMPtr<nsIDOMNSDocument> doc = do_QueryInterface(DOMDocument);
+	if (!doc) return NS_ERROR_FAILURE;
+#else
 	nsCOMPtr<nsIDOMNSHTMLDocument> doc = do_QueryInterface(DOMDocument);
 	if(!doc) return NS_ERROR_FAILURE;
+#endif
 
 	nsAutoString value;
 	doc->GetLastModified(value);
