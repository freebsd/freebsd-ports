--- embed/mozilla/EphyWrapper.cpp.orig	Sat Nov  1 22:42:25 2003
+++ embed/mozilla/EphyWrapper.cpp	Sat Nov  1 22:53:59 2003
@@ -582,8 +582,13 @@
 	nsCOMPtr<nsIDocument> doc = do_QueryInterface(DOMDocument);
 	if(!doc) return NS_ERROR_FAILURE;
 
+#if MOZILLA_SNAPSHOT > 11
+	nsIURI *uri;
+	uri = doc->GetDocumentURL ();
+#else
 	nsCOMPtr<nsIURI> uri;
 	doc->GetDocumentURL(getter_AddRefs(uri));
+#endif
 
 	return uri->GetSpec (url);
 }
@@ -600,8 +605,13 @@
         nsCOMPtr<nsIDocument> doc = do_QueryInterface(DOMDocument);
         if(!doc) return NS_ERROR_FAILURE;
 
+#if MOZILLA_SNAPSHOT > 11
+	nsIURI *uri;
+	uri = doc->GetDocumentURL ();
+#else
         nsCOMPtr<nsIURI> uri;
         doc->GetDocumentURL(getter_AddRefs(uri));
+#endif
 
         uri->GetSpec (url);
 
