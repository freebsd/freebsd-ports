--- spunk/coll.h.orig	Thu Dec 23 20:58:57 2004
+++ spunk/coll.h	Thu Dec 23 20:50:11 2004
@@ -418,15 +418,15 @@
 
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
@@ -461,7 +461,7 @@
 {
     // do a binary search
     int First = 0;
-    int Last = Count - 1;
+    int Last = this->Count - 1;
     int Current;
     int Result;
     int S = 0;
@@ -472,7 +472,7 @@
 	Current = (Last + First) / 2;
 
 	// Do a compare
-	Result = Compare (KeyOf ((T*) Items [Current]), Key);
+	Result = Compare (KeyOf ((T*) this->Items [Current]), Key);
 	if (Result < 0) {
 	    First = Current + 1;
 	} else {
@@ -516,7 +516,7 @@
     int I;
     if (Search (Key, I) != 0) {
 	// We found the key, I is the index
-	return At (I);
+	return this->At (I);
     } else {
 	// We did not find the key
 	return 0;
