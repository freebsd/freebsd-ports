--- src/DB.cpp.orig	2007-07-31 20:15:48.000000000 +0200
+++ src/DB.cpp	2007-07-31 20:16:18.000000000 +0200
@@ -521,7 +521,7 @@
 int DB::containsElementAtIndex(int i)
 {
 	if ( (i >= 0) && (i < DBSize) )
-		return (int)myDB[i];
+		return (long)myDB[i];
 
 	return 0;
 }
