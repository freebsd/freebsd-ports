--- src/core/unix/unixfsservices.cpp.orig	Sat Feb 24 11:02:12 2001
+++ src/core/unix/unixfsservices.cpp	Tue Jul 10 21:40:37 2001
@@ -243,6 +243,7 @@
 {
     char* pchTempFileName;
     char szTemplate[MAXPATHLEN];
+    int fd;
 
 #ifdef _UNICODE
     // convert template from wide character to multi-byte string
@@ -253,13 +254,14 @@
     strcpy( szTemplate, strName.c_str() );
 #endif
 
-    // create temp filename
-    pchTempFileName = mktemp( szTemplate );
+    // create temp filename and check to see if mkstemp failed
+   if ((fd = mkstemp( szTemplate )) == -1) {
+     throw eFSServicesGeneric( strName );
+   } else {
+     close(fd);
+   }
+   pchTempFileName = szTemplate;
 
-    //check to see if mktemp failed
-    if ( pchTempFileName == NULL || strlen(pchTempFileName) == 0) {
-      throw eFSServicesGeneric( strName );
-    }
 
     // change name so that it has the XXXXXX part filled in
 #ifdef _UNICODE
