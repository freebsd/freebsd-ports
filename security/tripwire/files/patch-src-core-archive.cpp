--- src/core/archive.cpp.orig	2016-04-23 19:12:41.000000000 -0700
+++ src/core/archive.cpp	2016-04-29 23:21:27.059769000 -0700
@@ -919,8 +919,8 @@
   }//try
   catch (eFile& fileError) {
     TSTRING errStr = TSS_GetString( cCore, core::STR_BAD_TEMPDIRECTORY );
-    eArchiveOpen e(strTempFile, errStr);
-    throw e;
+    eArchiveOpen e2(strTempFile, errStr);
+    throw e2;
   }
 
   ///////////////////////////////////////////////////////////////////////////////
