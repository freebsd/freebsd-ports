--- spunk/coll.h.orig	Wed Dec 18 23:42:14 1996
+++ spunk/coll.h	Sun Oct  8 10:19:16 2006
@@ -24,7 +24,7 @@
 
 
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "check.h"
 #include "object.h"
@@ -33,8 +33,8 @@
 
 
 
-static const coIndexError	= 1;		// Index out of range
-static const coOverflowError	= 2;		// Collection overflow
+static const int coIndexError		= 1;		// Index out of range
+static const int coOverflowError	= 2;		// Collection overflow
 
 
 
@@ -479,15 +479,15 @@
 
     // Duplicates allowed. Do a linear search.
     // (Hint: Search returns the first of all entrys with the same key)
-    Item2 = (T*) Items [Index];
+    Item2 = (T*) this->Items [Index];
     do {
 	if (Item2 == Item) {
 	    // That's it !
 	    return Index;
 	}
 	// Get next
-	Item2 = (T*) Items [++Index];
-    } while (Index < Count && Compare (Key, KeyOf (Item2)) == 0);
+	Item2 = (T*) this->Items [++Index];
+    } while (Index < this->Count && Compare (Key, KeyOf (Item2)) == 0);
 
     // Item not found
     return -1;
@@ -522,7 +522,7 @@
 {
     // do a binary search
     int First = 0;
-    int Last = Count - 1;
+    int Last = this->Count - 1;
     int Current;
     int Result;
     int S = 0;
@@ -533,7 +533,7 @@
 	Current = (Last + First) / 2;
 
 	// Do a compare
-	Result = Compare (KeyOf ((T*) Items [Current]), Key);
+	Result = Compare (KeyOf ((T*) this->Items [Current]), Key);
 	if (Result < 0) {
 	    First = Current + 1;
 	} else {
@@ -577,7 +577,7 @@
     int I;
     if (Search (Key, I) != 0) {
 	// We found the key, I is the index
-	return At (I);
+	return this->At (I);
     } else {
 	// We did not find the key
 	return 0;
