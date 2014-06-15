--- src/core/unixfsservices.cpp.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/core/unixfsservices.cpp	2014-06-15 01:44:45.000000000 +0200
@@ -792,7 +792,7 @@ bool cUnixFSServices::FullPath( TSTRING&
 // Returns normal string to append to backup files for this os.
 // (e.g. "~" for unix and ".bak" for winos)
 ///////////////////////////////////////////////////////////////////////////////
-TCHAR* cUnixFSServices::GetStandardBackupExtension() const
+const TCHAR* cUnixFSServices::GetStandardBackupExtension() const
 {
     return _T(".bak");
 }
