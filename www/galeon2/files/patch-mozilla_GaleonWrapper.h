--- mozilla/GaleonWrapper.h.orig	Mon Apr  7 18:48:36 2003
+++ mozilla/GaleonWrapper.h	Mon Apr  7 18:48:49 2003
@@ -91,7 +91,7 @@
 
 	nsresult GoToHistoryIndex (PRInt16 index);
 
-	nsresult ForceCharacterSet (char *charset);
+	nsresult ForceCharacterSet (const char *charset);
 
 	nsresult CanCutSelection(PRBool *result);
 
