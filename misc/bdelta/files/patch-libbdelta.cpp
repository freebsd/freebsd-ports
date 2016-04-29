--- libbdelta.cpp.orig	2016-04-26 04:19:52 UTC
+++ libbdelta.cpp
@@ -118,7 +118,7 @@ unsigned match_backward(BDelta_Instance 
 template <class T>
 inline T prior(T i) {return --i;}
 template <class T>
-inline T next(T i) {return ++i;}
+inline T bnext(T i) {return ++i;}
 
 
 struct UnusedRange {
@@ -421,7 +421,7 @@ void bdelta_pass(BDelta_Instance *b, uns
 			UnusedRange u1 = unused[i], u2 = unused2[i];
 			if (u1.num >= blocksize && u2.num >= blocksize)
 				if (! maxHoleSize || (u1.num <= maxHoleSize && u2.num <= maxHoleSize))
-					if (! (flags & BDELTA_SIDES_ORDERED) || (next(u1.ml) == u1.mr && next(u2.ml) == u2.mr))
+					if (! (flags & BDELTA_SIDES_ORDERED) || (bnext(u1.ml) == u1.mr && bnext(u2.ml) == u2.mr))
 						bdelta_pass_2(b, blocksize, minMatchSize, &u1, 1, &u2, 1);
 		}
 	}
