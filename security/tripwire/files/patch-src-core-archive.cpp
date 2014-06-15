--- src/core/archive.cpp.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/core/archive.cpp	2014-06-15 01:45:01.000000000 +0200
@@ -886,8 +886,8 @@ void cLockedTemporaryFileArchive::OpenRe
         catch( eFSServices& e)
           {
             TSTRING errStr = TSS_GetString( cCore, core::STR_BAD_TEMPDIRECTORY );
-            eArchiveOpen e(strTempFile, errStr);
-            throw e;
+            eArchiveOpen e2(strTempFile, errStr);
+            throw e2;
           }
       }
     ///////////////////////////////////////////////////////////////////////////////
