--- toolkit/xre/nsXREDirProvider.cpp.orig	Sat Jan 27 15:13:33 2007
+++ toolkit/xre/nsXREDirProvider.cpp
@@ -836,6 +836,7 @@
  
   char* appNameFolder = nsnull;
   char profileFolderName[MAXPATHLEN] = ".";
+  char temp[MAXPATHLEN];
  
   // Offset 1 for the outermost folder to make it hidden (i.e. using the ".")
   char* writing = profileFolderName + 1;
@@ -845,7 +846,6 @@
     rv = localDir->AppendNative(nsDependentCString(profileFolderName));
     NS_ENSURE_SUCCESS(rv, rv);
  
-    char temp[MAXPATHLEN];
     GetProfileFolderName(temp, gAppData->name);
     appNameFolder = temp;
   }
