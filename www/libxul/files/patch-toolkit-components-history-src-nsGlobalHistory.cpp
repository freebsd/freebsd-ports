--- toolkit/components/history/src/nsGlobalHistory.cpp.orig	2006-02-02 20:55:17.000000000 +0100
+++ toolkit/components/history/src/nsGlobalHistory.cpp
@@ -322,7 +322,9 @@ matchAgeInDaysCallback(nsIMdbRow *row, v
   if (err != 0) return PR_FALSE;
   
   PRTime rowDate;
-  PR_sscanf((const char*)yarn.mYarn_Buf, "%lld", &rowDate);
+  long long ld;
+  PR_sscanf((const char*)yarn.mYarn_Buf, "%lld", &ld);
+  rowDate = ld;
 
   PRInt32 days = GetAgeInDays(matchSearchTerm->now, rowDate);
   
@@ -1067,7 +1069,9 @@ nsGlobalHistory::GetRowValue(nsIMdbRow *
   if (!yarn.mYarn_Fill || !yarn.mYarn_Buf)
     return NS_OK;
 
-  PR_sscanf((const char*)yarn.mYarn_Buf, "%lld", aResult);
+  long long ld;
+  PR_sscanf((const char*)yarn.mYarn_Buf, "%lld", &ld);
+  *aResult = ld;
   
   return NS_OK;
 }
