--- src/core/fsservices.h.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/core/fsservices.h	2014-06-15 01:54:49.000000000 +0200
@@ -177,6 +177,7 @@ TSS_FILE_EXCEPTION( eFSServicesGeneric, 
 class iFSServices 
 {
  public:
+  virtual ~iFSServices() {}
     
   ///////////////////////////////////////////////////////////////
   // ENUMS
@@ -219,7 +220,7 @@ class iFSServices 
   // returns true if the file system is case sensitive
   virtual TCHAR       GetPathSeperator() const = 0;
   // returns "/" for unix and "\\" for win32
-  virtual TCHAR*      GetStandardBackupExtension() const = 0;
+  virtual const TCHAR* GetStandardBackupExtension() const = 0;
   // returns normal string to append to backup files for this os.
     
   ////////////////////////////////////////
