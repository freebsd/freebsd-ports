--- src/mozilla/GaleonWrapper.cpp.orig	Mon Apr  7 23:44:37 2003
+++ src/mozilla/GaleonWrapper.cpp	Mon Apr  7 23:44:44 2003
@@ -739,16 +739,24 @@
 
 	nsCOMPtr<nsIDOMDocument> aDOMDocument;
 
-	result = GetDOMDocument (getter_AddRefs(aDOMDocument));
+	result = GetDOMDocument(getter_AddRefs(aDOMDocument));
 	if (NS_FAILED(result) || !aDOMDocument) return NS_ERROR_FAILURE;
 
 	nsCOMPtr<nsIDocument> doc = do_QueryInterface(aDOMDocument);
-	if(!doc) return NS_ERROR_FAILURE;
+	if (!doc) return NS_ERROR_FAILURE;
+
+#if MOZILLA_SNAPSHOT > 6
+	nsString docTitle;
+	result = doc->GetDocumentTitle(docTitle);
+	if (NS_FAILED(result)) return NS_ERROR_FAILURE;
 
+	*title = mozilla_unicode_to_locale(docTitle.get());
+#else
 	const nsString* t;
 	t = doc->GetDocumentTitle();
 
-	*title = mozilla_unicode_to_locale (t->get());
+	*title = mozilla_unicode_to_locale(t->get());
+#endif
 
 	return NS_OK;
 }
@@ -815,30 +823,35 @@
 }
 
 
-nsresult GaleonWrapper::SetSitePermission (gboolean block, PRInt32 type)
+nsresult GaleonWrapper::SetSitePermission (PRBool allow, PRUint32 type)
 {
 	nsresult result;
 
 	nsCOMPtr<nsIDOMDocument> DOMDocument;
-	result = GetDOMDocument (getter_AddRefs(DOMDocument));
+	result = GetDOMDocument(getter_AddRefs(DOMDocument));
 	if (NS_FAILED(result) || !DOMDocument) return NS_ERROR_FAILURE;
 
-	nsCOMPtr<nsIDocument> doc = do_QueryInterface (DOMDocument);
+	nsCOMPtr<nsIDocument> doc = do_QueryInterface(DOMDocument);
 	if (!doc) return NS_ERROR_FAILURE;
 	
 	nsCOMPtr<nsIURI> uri;
 	doc->GetDocumentURL(getter_AddRefs(uri));
 
 	nsCAutoString url;
-	uri->GetSpec (url);
+	uri->GetSpec(url);
 	
 	nsCOMPtr<nsIPermissionManager> permissionManager =
-			do_CreateInstance (NS_PERMISSIONMANAGER_CONTRACTID);
+			do_GetService(NS_PERMISSIONMANAGER_CONTRACTID);
 
-#if MOZILLA_SNAPSHOT > 2
-	result = permissionManager->Add (url, block ? PR_TRUE : PR_FALSE, type);
+#if MOZILLA_SNAPSHOT > 6
+	result = permissionManager->Add(uri, type,
+					allow ?
+					static_cast<PRUint32>(nsIPermissionManager::ALLOW_ACTION) :
+					static_cast<PRUint32>(nsIPermissionManager::DENY_ACTION));
+#elif MOZILLA_SNAPSHOT > 2
+	result = permissionManager->Add (url, allow, type);
 #else
-	result = permissionManager->Add (url.get(), block ? PR_TRUE : PR_FALSE, type);
+	result = permissionManager->Add (url.get(), allow, type);
 #endif
 
 	return result;
