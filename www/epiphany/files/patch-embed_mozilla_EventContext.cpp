--- embed/mozilla/EventContext.cpp.orig	Sat Nov  1 22:42:40 2003
+++ embed/mozilla/EventContext.cpp	Sat Nov  1 22:57:20 2003
@@ -139,13 +139,19 @@
 nsresult EventContext::ResolveBaseURL (nsIDocument *doc, const nsAString &relurl, nsACString &url)
 {
 	nsresult rv;
+#if MOZILLA_SNAPSHOT > 11
+	nsIURI *base;
+	base = doc->GetBaseURL ();
+	if (base == NULL) return NS_ERROR_FAILURE;
+#elif MOZILLA_SNAPSHOT > 9
 	nsCOMPtr<nsIURI> base;
-#if MOZILLA_SNAPSHOT > 9
 	rv = doc->GetBaseURL (getter_AddRefs(base));
+	if (NS_FAILED(rv)) return rv;
 #else
+	nsCOMPtr<nsIURI> base;
 	rv = doc->GetBaseURL (*getter_AddRefs(base));
-#endif
 	if (NS_FAILED(rv)) return rv;
+#endif
 
 	return base->Resolve (NS_ConvertUCS2toUTF8(relurl), url);
 }
@@ -153,9 +159,15 @@
 nsresult EventContext::ResolveDocumentURL (nsIDocument *doc, const nsAString &relurl, nsACString &url)
 {
 	nsresult rv;
+#if MOZILLA_SNAPSHOT > 11
+	nsIURI *uri;
+	uri = doc->GetDocumentURL ();
+	if (uri == NULL) return NS_ERROR_FAILURE;
+#else
 	nsCOMPtr<nsIURI> uri;
 	rv = doc->GetDocumentURL(getter_AddRefs(uri));
 	if (NS_FAILED(rv)) return rv;
+#endif
 
 	return uri->Resolve (NS_ConvertUCS2toUTF8(relurl), url);
 }
