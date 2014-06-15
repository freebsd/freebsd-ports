--- src/core/unixfsservices.h.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/core/unixfsservices.h	2014-06-15 01:44:45.000000000 +0200
@@ -99,7 +99,7 @@ class cUnixFSServices : public iFSServic
   ////////////////////////////////////////
   virtual bool    IsCaseSensitive() const;
   // returns true if the file system is case sensitive
-  virtual TCHAR*      GetStandardBackupExtension() const;
+  virtual const TCHAR* GetStandardBackupExtension() const;
   // returns normal string to append to backup files for this os.
   // (e.g. "~" for unix and ".bak" for winos)
   virtual TCHAR       GetPathSeperator() const;
