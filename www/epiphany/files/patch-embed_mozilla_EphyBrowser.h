--- embed/mozilla/EphyBrowser.h.orig	Sun Jul 18 19:11:02 2004
+++ embed/mozilla/EphyBrowser.h	Sun Jul 18 19:11:34 2004
@@ -104,7 +104,7 @@
 
 	nsresult GetSHInfo (PRInt32 *count, PRInt32 *index);
 	nsresult GetSHTitleAtIndex (PRInt32 index, PRUnichar **title);
-	nsresult GetSHUrlAtIndex (PRInt32 index, nsCString &url);
+	nsresult GetSHUrlAtIndex (PRInt32 index, nsACString &url);
 	nsresult GoToHistoryIndex (PRInt16 index);
 
 	nsresult ForceEncoding (const char *encoding);
@@ -116,8 +116,8 @@
 
 	nsresult GetDocument (nsIDOMDocument **aDOMDocument);
 	nsresult GetTargetDocument (nsIDOMDocument **aDOMDocument);
-	nsresult GetDocumentUrl (nsCString &url);
-	nsresult GetTargetDocumentUrl (nsCString &url);
+	nsresult GetDocumentUrl (nsACString &url);
+	nsresult GetTargetDocumentUrl (nsACString &url);
 
 	nsresult GetHasModifiedForms (PRBool *modified);
 
