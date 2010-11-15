--- isoqlog/Data.h.orig	2010-08-09 16:53:36.000000000 +0200
+++ isoqlog/Data.h	2010-08-09 16:53:40.000000000 +0200
@@ -99,7 +99,7 @@
 struct UsersTab {
 	int nval;
 	int max;
-	int *allusers;
+	user**allusers;
 } UsersTab;
 
 
@@ -107,7 +107,7 @@
 struct SortDomain {
 	int nval;
 	int max;
-	int *allusers;
+	user**allusers;
 } SortDomain;
 	
 #endif
