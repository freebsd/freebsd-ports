--- khtml/html/html_documentimpl.cpp.orig	2007-08-08 13:44:11.000000000 +0200
+++ khtml/html/html_documentimpl.cpp	2007-08-08 13:45:49.000000000 +0200
@@ -270,7 +270,7 @@
 	return;
     }
  
-    int oldCount = (int)namedImageAndFormCounts.find(name);
+    intptr_t oldCount = (intptr_t)namedImageAndFormCounts.find(name);
     namedImageAndFormCounts.insert(name, (char *)(oldCount + 1));
 }
 
@@ -280,9 +280,9 @@
 	return;
     }
  
-    int oldVal = (int)(namedImageAndFormCounts.find(name));
+    intptr_t oldVal = (intptr_t)(namedImageAndFormCounts.find(name));
     if (oldVal != 0) {
-	int newVal = oldVal - 1;
+	intptr_t newVal = oldVal - 1;
 	if (newVal == 0) {
 	    namedImageAndFormCounts.remove(name);
 	} else {
