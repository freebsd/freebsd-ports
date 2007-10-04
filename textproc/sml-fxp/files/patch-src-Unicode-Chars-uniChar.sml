diff -Naur src/Unicode/Chars/uniChar.sml.orig src/Unicode/Chars/uniChar.sml
--- src/Unicode/Chars/uniChar.sml.orig	2003-10-09 09:47:58.000000000 -0500
+++ src/Unicode/Chars/uniChar.sml	2003-10-17 13:43:07.000000000 -0500
@@ -108,10 +108,14 @@
 	    if len<=maxlen orelse maxlen=0 
 	       then Data2String (Vector2Data vec)
 	    else let 
-		    val cs1 = Vector.foldri 
-		       (fn (_,c,cs) => c::cs) nil (vec,0,SOME (maxlen div 2))
-		    val cs2 = Vector.foldri 
-		       (fn (_,c,cs) => c::cs) nil (vec,len-3-maxlen div 2,NONE)
+		    val cs1 = VectorSlice.foldri
+		       (fn (_,c,cs) => c::cs)
+		       nil
+		       (VectorSlice.slice (vec,0,SOME (maxlen div 2)))
+		    val cs2 = VectorSlice.foldri 
+		       (fn (_,c,cs) => c::cs)
+		       nil
+		       (VectorSlice.slice (vec,len-3-maxlen div 2,NONE))
 		 in Data2String cs1^"..."^Data2String cs2
 		 end
 	 end
