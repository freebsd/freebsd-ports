--- update-mime-database.c.orig	Mon Oct 13 11:43:38 2003
+++ update-mime-database.c	Mon Apr 12 22:45:01 2004
@@ -377,7 +377,8 @@
 		}
 	}
 
-	xmlFree(lang);
+	if (lang)
+	  xmlFree(lang);
 }
 
 /* 'node' is a <mime-type> node from a source file, whose type is 'type'.
