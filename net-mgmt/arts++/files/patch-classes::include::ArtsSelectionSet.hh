--- ./classes/include/ArtsSelectionSet.hh.orig	Mon Oct  2 13:05:20 2000
+++ ./classes/include/ArtsSelectionSet.hh	Wed Sep 25 16:38:10 2002
@@ -49,6 +49,7 @@
 
 #include <vector>
 #include <algorithm>
+using namespace std;
 
 #include "ArtsSelection.hh"
 
@@ -96,7 +97,7 @@
   //-------------------------------------------------------------------------
   bool Matches(const Type & value) const
   {
-    const_iterator  selectionIter;
+    typename ArtsSelectionSet<Type>::const_iterator  selectionIter;
     bool            rc = false;
 
     for (selectionIter = this->begin(); selectionIter != this->end();
