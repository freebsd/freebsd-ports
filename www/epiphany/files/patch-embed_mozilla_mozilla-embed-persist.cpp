--- embed/mozilla/mozilla-embed-persist.cpp.orig	Sat Nov  1 23:12:09 2003
+++ embed/mozilla/mozilla-embed-persist.cpp	Sun Nov  2 00:03:17 2003
@@ -254,9 +254,15 @@
                                 do_QueryInterface (DOMDocument, &rv);
         	if (NS_FAILED(rv) || !document) return G_FAILED;
 
+#if MOZILLA_SNAPSHOT > 11
+	        nsIURI *uri;
+	        uri = document->GetDocumentURL ();
+	        if (uri == NULL) return G_FAILED;
+#else
 	        nsCOMPtr<nsIURI> uri;
         	rv = document->GetDocumentURL (getter_AddRefs(uri));
         	if (NS_FAILED(rv) || !uri) return G_FAILED;
+#endif
 
         	aProgress->InitForPersist (bpersist, parent,
                    	                   uri, file, 
