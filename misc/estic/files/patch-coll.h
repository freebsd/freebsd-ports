--- spunk/coll.h.orig	1996-12-18 22:42:14 UTC
+++ spunk/coll.h
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
 
 
 
@@ -479,15 +479,15 @@ int SortedCollection<T, U>::IndexOf (con
 
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
@@ -512,7 +512,7 @@ void SortedCollection<T, U>::Insert (T* 
     }
 
     // Index points to the correct position, insert item
-    AtInsert (Index, Item);
+    this->AtInsert (Index, Item);
 }
 
 
@@ -522,7 +522,7 @@ int SortedCollection<T, U>::Search (cons
 {
     // do a binary search
     int First = 0;
-    int Last = Count - 1;
+    int Last = this->Count - 1;
     int Current;
     int Result;
     int S = 0;
@@ -533,7 +533,7 @@ int SortedCollection<T, U>::Search (cons
 	Current = (Last + First) / 2;
 
 	// Do a compare
-	Result = Compare (KeyOf ((T*) Items [Current]), Key);
+	Result = Compare (KeyOf ((T*) this->Items [Current]), Key);
 	if (Result < 0) {
 	    First = Current + 1;
 	} else {
@@ -577,7 +577,7 @@ T* SortedCollection<T, U>::Find (const U
     int I;
     if (Search (Key, I) != 0) {
 	// We found the key, I is the index
-	return At (I);
+	return this->At (I);
     } else {
 	// We did not find the key
 	return 0;
