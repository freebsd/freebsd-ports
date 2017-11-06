--- isoqlog/Data.h.orig	2003-02-04 08:35:42 UTC
+++ isoqlog/Data.h
@@ -99,7 +99,7 @@ struct DomainsTab {
 struct UsersTab {
 	int nval;
 	int max;
-	int *allusers;
+	user**allusers;
 } UsersTab;
 
 
@@ -107,7 +107,7 @@ struct UsersTab {
 struct SortDomain {
 	int nval;
 	int max;
-	int *allusers;
+	user**allusers;
 } SortDomain;
 	
 #endif
