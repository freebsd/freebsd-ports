--- bk/bkPath.c.orig	Sun Jan  7 20:00:36 2007
+++ bk/bkPath.c
@@ -110,7 +110,7 @@
     int count;
     int srcLen;
     int lastCharIndex;
-    int firstCharIndex;
+    int firstCharIndex=0;
     bool lastCharFound;
     int count2;
     
@@ -162,6 +162,9 @@
 {
     int count;
     int pathStrLen;
+    int numChildrenDone;
+    int nextChildLen;
+    const char* nextChild;
     
     pathStrLen = strlen(strPath);
     
@@ -186,9 +189,9 @@
     if(pathPath->children == NULL)
         return BKERROR_OUT_OF_MEMORY;
     
-    int numChildrenDone = 0;
-    int nextChildLen = 0;
-    const char* nextChild = &(strPath[1]);
+    numChildrenDone = 0;
+    nextChildLen = 0;
+    nextChild = &(strPath[1]);
     for(count = 1; count <= pathStrLen; count++)
     {
         if(strPath[count] == '/' || (strPath[count] == '\0' && strPath[count - 1] != '/'))
