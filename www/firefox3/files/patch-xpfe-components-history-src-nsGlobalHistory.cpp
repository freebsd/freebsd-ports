--- xpfe/components/history/src/nsGlobalHistory.cpp.orig	2007-12-03 05:25:14.000000000 +0100
+++ xpfe/components/history/src/nsGlobalHistory.cpp
@@ -304,7 +304,9 @@ matchAgeInDaysCallback(nsIMdbRow *row, v
   if (err != 0) return PR_FALSE;
   
   PRTime rowDate;
-  PR_sscanf((const char*)yarn.mYarn_Buf, "%lld", &rowDate);
+  long long ld;
+  PR_sscanf((const char*)yarn.mYarn_Buf, "%lld", &ld);
+  rowDate = ld;
 
   PRInt32 days = matchSearchTerm->globalHist->GetAgeInDays(rowDate);
   
@@ -1000,7 +1002,9 @@ nsGlobalHistory::GetRowValue(nsIMdbRow *
   if (!yarn.mYarn_Fill || !yarn.mYarn_Buf)
     return NS_OK;
 
-  PR_sscanf((const char*)yarn.mYarn_Buf, "%lld", aResult);
+  long long ld;
+  PR_sscanf((const char*)yarn.mYarn_Buf, "%lld", &ld);
+  *aResult = ld;
 
   return NS_OK;
 }
