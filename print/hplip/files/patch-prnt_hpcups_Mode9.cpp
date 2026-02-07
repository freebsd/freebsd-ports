--- prnt/hpcups/Mode9.cpp.orig	2023-06-02 08:02:35 UTC
+++ prnt/hpcups/Mode9.cpp
@@ -203,7 +203,7 @@ bool Mode9::Process(RASTERDATA* input)
     unsigned int    offset,byte_count,rem_count;
     Mode9_comtype       command;
     char* dest=    (char*) compressBuf;
-    register char *dptr=dest;
+    char *dptr=dest;
 
     while ( size > 0 )
     {
