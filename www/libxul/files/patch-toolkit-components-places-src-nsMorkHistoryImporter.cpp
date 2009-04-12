--- toolkit/components/places/src/nsMorkHistoryImporter.cpp.orig	2008-03-19 20:30:49.000000000 +0100
+++ toolkit/components/places/src/nsMorkHistoryImporter.cpp	2008-12-17 09:38:05.000000000 +0100
@@ -148,9 +148,12 @@ AddToHistoryCB(const nsCSubstring &aRowI
     }
 
     PRTime date;
-    if (PR_sscanf(values[kLastVisitColumn].get(), "%lld", &date) != 1) {
+    long long ld;
+    if (PR_sscanf(values[kLastVisitColumn].get(), "%lld", &ld) != 1) {
       date = -1;
-    }
+    } else {
+      date = ld;
+   }
 
     PRBool isTyped = values[kTypedColumn].EqualsLiteral("1");
     PRInt32 transition = isTyped ?
