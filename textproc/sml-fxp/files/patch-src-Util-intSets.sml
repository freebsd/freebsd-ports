diff -Naur src/Util/intSets.sml.orig src/Util/intSets.sml
--- src/Util/intSets.sml.orig	2003-10-09 09:47:58.000000000 -0500
+++ src/Util/intSets.sml	2003-10-17 14:20:11.000000000 -0500
@@ -49,8 +49,8 @@
 
       fun normalize (vec:IntSet) = 
 	 let val max = Vector.foldli
-	    (fn (i,w,max) => if w=0wx0 then i else max) 0 (vec,0,NONE)
-	 in Vector.extract (vec,0,SOME max)
+            (fn (i,w,max) => if w=0wx0 then i else max) 0 vec
+         in VectorSlice.vector(VectorSlice.slice (vec,0,SOME max))
 	 end
 
       val emptyIntSet = Vector.fromList nil : IntSet
@@ -88,7 +88,7 @@
 	    val size = Vector.length vec
 	 in 
 	    if size>idx 
-	       then Vector.mapi (fn (i,x) => if i=idx then x||mask else x) (vec,0,NONE)
+	       then Vector.mapi (fn (i,x) => if i=idx then x||mask else x) vec
 	    else Vector.tabulate 
 	       (idx+1,fn i => if i<size then Vector.sub(vec,i) else if i=idx then mask else 0w0)
 	 end
@@ -100,7 +100,7 @@
 	    val vec1 = if size<=idx then vec
 		       else let val mask = !! (0w1 << (Word.fromInt (n mod wordSize)))
 			    in Vector.mapi 
-			       (fn (i,x) => if i=idx then x && mask else x) (vec,0,NONE)
+                               (fn (i,x) => if i=idx then x && mask else x) vec
 			    end
 	 in normalize vec1
 	 end
