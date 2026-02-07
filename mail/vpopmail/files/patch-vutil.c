Description: Sanity and safety.
 Optimize a lot of calls by just using access(2).
 Fix a file descriptor and FILE structure leak.
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2009-11-26

--- a/vutil.c
+++ b/vutil.c
@@ -76,13 +76,7 @@
   */
 
 int file_exists (char *filename) {
-    FILE *fs;
-    if( (fs=fopen(filename, "r")) !=NULL ) {
-        fclose(fs);
-        return 1;
-    } else {
-        return 0;
-    }
+    return(access(filename, R_OK) == 0);
 }
 
 //////////////////////////////////////////////////////////////////////
@@ -100,24 +94,15 @@
 {
     FILE *fs = NULL;
     char FileName[MAX_BUFF];
-    int result = 0;
     char TmpBuf2[MAX_BUFF];
 
     snprintf( FileName, MAX_BUFF, "%s/.qmail-%s", path, Name );
-    if ( (fs=fopen(FileName,"r"))==NULL) {
-//        printf( "   Unable to open list file: %s\n", Name );
-    }
-
-    else {
-        fgets( TmpBuf2, sizeof(TmpBuf2), fs);
-        if ( strstr( TmpBuf2, "ezmlm-reject") != 0 ||
-             strstr( TmpBuf2, "ezmlm-send")   != 0 ) {
-            result = 1;
-        }
-        fclose(fs);
-    }
-
-    return result;
+    if ( (fs=fopen(FileName,"r"))==NULL)
+        return(0);
+    fgets( TmpBuf2, sizeof(TmpBuf2), fs);
+    fclose(fs);
+    return ( strstr( TmpBuf2, "ezmlm-reject") != 0 ||
+        strstr( TmpBuf2, "ezmlm-send")   != 0 );
 }
 
 
