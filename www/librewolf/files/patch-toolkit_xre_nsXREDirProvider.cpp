--- toolkit/xre/nsXREDirProvider.cpp.orig
+++ toolkit/xre/nsXREDirProvider.cpp
@@ -1614,6 +1614,7 @@

     rv = AppendProfileString(aFile, folder.BeginReading());
   } else {
+    appName = nsAutoCString("librewolf");
     if (!vendor.IsEmpty()) {
       folder.Append(vendor);
       ToLowerCase(folder);

