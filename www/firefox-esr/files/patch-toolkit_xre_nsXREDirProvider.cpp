--- toolkit/xre/nsXREDirProvider.cpp.orig	Tue Oct  4 11:46:26 2005
+++ toolkit/xre/nsXREDirProvider.cpp	Sun Feb  5 23:54:31 2006
@@ -820,6 +820,7 @@
  
   char* appNameFolder = nsnull;
   char profileFolderName[MAXPATHLEN] = ".";
+  char temp[MAXPATHLEN];
  
   // Offset 1 for the outermost folder to make it hidden (i.e. using the ".")
   char* writing = profileFolderName + 1;
@@ -829,7 +830,6 @@
     rv = localDir->AppendNative(nsDependentCString(profileFolderName));
     NS_ENSURE_SUCCESS(rv, rv);
  
-    char temp[MAXPATHLEN];
     GetProfileFolderName(temp, gAppData->name);
     appNameFolder = temp;
   }

