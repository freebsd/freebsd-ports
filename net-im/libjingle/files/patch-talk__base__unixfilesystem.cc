--- talk/base/unixfilesystem.cc.orig	2008-09-06 23:32:04.000000000 -0300
+++ talk/base/unixfilesystem.cc	2008-09-06 23:33:03.000000000 -0300
@@ -111,6 +111,7 @@
     if (create)
       CreateFolder(pathname);
   }
+  return true;
 }
 
 std::string UnixFilesystem::TempFilenameI(const Pathname &dir, const std::string &prefix) {
