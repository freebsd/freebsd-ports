--- mozilla/TOCProtocolHandler.cpp.orig	Wed Sep  4 20:41:48 2002
+++ mozilla/TOCProtocolHandler.cpp	Thu Feb 13 16:15:50 2003
@@ -83,8 +83,8 @@
 	oStream->Write (str.c_str(), str.size(), &bytesWriten);
 
 void ParseEnvPath(const nsCString &path, list<string> &dirs);
-int gHelpSelect (const struct dirent *dirEntry);
-int gnomeHelpSelect (const struct dirent *dirEntry);
+int gHelpSelect (struct dirent *dirEntry);
+int gnomeHelpSelect (struct dirent *dirEntry);
 
 /* Implementation file */
 NS_IMPL_ISUPPORTS1 (GTOCProtocolHandler, nsIProtocolHandler)
@@ -126,17 +126,24 @@
 	if (NS_FAILED(rv)) return rv;
 
 	/* finish the rendering */
-	PRUint32 size;  
-	rv = mStream->GetLength(&size);
-	if (NS_FAILED(rv)) return rv;
 
 	nsCOMPtr<nsIInputStream> iStream;
 	rv = mStream->NewInputStream(0, getter_AddRefs(iStream));
 	if (NS_FAILED(rv)) return rv;
 
+#if MOZILLA_SNAPSHOT > 3
+	rv = NS_NewInputStreamChannel(getter_AddRefs(mChannel), mURI,
+				      iStream, NS_LITERAL_CSTRING("text/html"),
+				      NS_LITERAL_CSTRING("utf-8"));
+#else
+	PRUint32 size;
+	rv = mStream->GetLength(&size);
+	if (NS_FAILED(rv)) return rv;
+
 	rv = NS_NewInputStreamChannel(getter_AddRefs(mChannel), mURI,
 				      iStream, NS_LITERAL_CSTRING("text/html"),
 				      NS_LITERAL_CSTRING("utf-8"), size);
+#endif
 	if (NS_FAILED(rv)) return rv;
 
 	return rv;
@@ -401,7 +408,7 @@
 }
 
 NS_METHOD GTOCProtocolHandler::CreateHelpPage (const char *type,
-					       int (*select)(const struct dirent *))
+					       int (*select)(struct dirent *))
 {
 	nsresult rv;
 
@@ -496,7 +503,7 @@
 	}
 }
 
-int gHelpSelect (const struct dirent *dirEntry)
+int gHelpSelect (struct dirent *dirEntry)
 {
 #ifdef NOT_PORTED
 	char *helpPath = gnome_help_file_find_file (
@@ -512,7 +519,7 @@
 #endif
 }
 
-int gnomeHelpSelect (const struct dirent *dirEntry)
+int gnomeHelpSelect (struct dirent *dirEntry)
 {
 #ifdef NOT_PORTED
 	nsCString fileName = dirEntry->d_name;
