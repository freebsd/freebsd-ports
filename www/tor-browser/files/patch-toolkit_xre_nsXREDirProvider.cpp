--- toolkit/xre/nsXREDirProvider.cpp.orig	2023-09-26 21:44:17 UTC
+++ toolkit/xre/nsXREDirProvider.cpp
@@ -1788,6 +1788,10 @@ nsresult nsXREDirProvider::AppendProfilePath(nsIFile* 
 
       rv = aFile->AppendNative(folder);
     }
+
+    // FreeBSD PR 268684
+    nsAutoCString folder(".tor-browser-profiles");
+    rv = aFile->AppendNative(folder);
   }
   NS_ENSURE_SUCCESS(rv, rv);
 
