--- src/mozilla/GaleonWrapper.h.orig	Mon Apr  7 23:45:09 2003
+++ src/mozilla/GaleonWrapper.h	Mon Apr  7 23:45:14 2003
@@ -80,7 +80,7 @@
 
 	nsresult GoToHistoryIndex (PRInt16 index);
 
-	nsresult SetSitePermission( PRBool permission, PRInt32 type );
+	nsresult SetSitePermission( PRBool permission, PRUint32 type );
 
 	nsresult ForceCharacterSet (char *charset);
 
