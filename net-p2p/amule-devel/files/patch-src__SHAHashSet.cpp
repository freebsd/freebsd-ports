--- src/SHAHashSet.cpp.orig	2012-05-11 20:38:43.000000000 +0200
+++ src/SHAHashSet.cpp	2012-10-13 12:29:25.000000000 +0200
@@ -702,7 +702,8 @@
 		return false;
 	}
 
-	FreeHashSet();
+	//Backported from r10793
+	//FreeHashSet();
 	return true;
 }
 
