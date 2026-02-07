--- toolkit/xre/nsXREDirProvider.cpp.orig	2024-03-19 15:15:35 UTC
+++ toolkit/xre/nsXREDirProvider.cpp
@@ -1430,7 +1430,7 @@ nsresult nsXREDirProvider::AppendProfilePath(nsIFile* 
   if (gAppData->profile) {
     profile = gAppData->profile;
   } else {
-    appName = gAppData->name;
+    appName = "Librewolf";
     vendor = gAppData->vendor;
   }

