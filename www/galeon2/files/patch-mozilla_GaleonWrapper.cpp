--- mozilla/GaleonWrapper.cpp.orig	Mon Apr  7 18:45:26 2003
+++ mozilla/GaleonWrapper.cpp	Mon Apr  7 18:45:35 2003
@@ -666,10 +666,16 @@
 	nsCOMPtr<nsIDocument> doc = do_QueryInterface(DOMDocument);
 	if(!doc) return NS_ERROR_FAILURE;
 
+#if MOZILLA_SNAPSHOT > 6
+	nsAutoString t;
+	doc->GetDocumentTitle(t);
+	*title = g_strdup (NS_ConvertUCS2toUTF8(t).get());
+#else
 	const nsString* t;
 	t = doc->GetDocumentTitle();
 
 	*title = g_strdup (NS_ConvertUCS2toUTF8(*t).get());
+#endif
 
 	return NS_OK;
 }
@@ -735,7 +741,7 @@
 	return NS_OK;
 }
 
-nsresult GaleonWrapper::ForceCharacterSet (char *charset) 
+nsresult GaleonWrapper::ForceCharacterSet (const char *charset) 
 {
 	nsresult result;
 
@@ -839,12 +845,7 @@
 	if (NS_FAILED(result)) return NS_ERROR_FAILURE;
 
 	nsICSSStyleSheet *sheet;
-#if MOZILLA_SNAPSHOT > 3
 	result = loader->LoadAgentSheet(uri, &sheet);
-#else
-	PRBool completed;
-	result = loader->LoadAgentSheet(uri, sheet, completed, nsnull);
-#endif
 	if (NS_FAILED(result)) return NS_ERROR_FAILURE;
 
 	/* catch stylesheet stuff and apply by appending it as a override
