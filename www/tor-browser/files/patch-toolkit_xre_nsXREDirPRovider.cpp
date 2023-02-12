--- toolkit/xre/nsXREDirProvider.cpp.orig	2023-01-15 10:55:50.058634000 +0100
+++ toolkit/xre/nsXREDirProvider.cpp	2023-01-15 10:56:48.735300000 +0100
@@ -1653,7 +1653,11 @@
     ToLowerCase(folder);
 
     rv = AppendProfileString(aFile, folder.BeginReading());
+  } else {
+    nsAutoCString folder(".tor-browser-profiles");
+    rv = aFile->AppendNative(folder);
   }
+
   NS_ENSURE_SUCCESS(rv, rv);
 
 #else
