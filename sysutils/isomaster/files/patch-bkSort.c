--- bk/bkSort.c.orig	Sat Dec 23 17:55:20 2006
+++ bk/bkSort.c
@@ -26,7 +26,7 @@
     int rightLen;
     int count;
     bool resultFound;
-    bool rc;
+    bool rc=false;
     
     leftLen = strlen(leftStr);
     rightLen = strlen(rightStr);
@@ -61,6 +61,8 @@
 void sortDir(DirToWrite* dir, int filenameType)
 {
     BaseToWrite* child;
+    BaseToWrite** outerPtr;
+    BaseToWrite** innerPtr;
     
     child = dir->children;
     while(child != NULL)
@@ -71,9 +73,6 @@
         child = child->next;
     }
     
-    BaseToWrite** outerPtr;
-    BaseToWrite** innerPtr;
-    
     outerPtr = &(dir->children);
     while(*outerPtr != NULL)
     {
@@ -90,19 +89,23 @@
                 
                 if( (*outerPtr)->next != *innerPtr )
                 {
+                    BaseToWrite* oldInnerNext;
+
                     *outerPtr = inner;
                     *innerPtr = outer;
                     
-                    BaseToWrite* oldInnerNext = inner->next;
+                    oldInnerNext = inner->next;
                     inner->next = outer->next;
                     outer->next = oldInnerNext;
                 }
                 else
                 {
+                    BaseToWrite* oldInnerNext = inner->next;
+
                     *outerPtr = inner;
                     innerPtr = &(inner->next);
                     
-                    BaseToWrite* oldInnerNext = inner->next;
+                    oldInnerNext = inner->next;
                     inner->next = outer;
                     outer->next = oldInnerNext;
                 }
