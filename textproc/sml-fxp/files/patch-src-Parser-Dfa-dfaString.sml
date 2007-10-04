diff -ruN src/Parser/Dfa/dfaString.sml.orig src/Parser/Dfa/dfaString.sml
--- src/Parser/Dfa/dfaString.sml.orig	2004-06-25 18:42:52.000000000 +0200
+++ src/Parser/Dfa/dfaString.sml	2004-12-08 19:02:48.000000000 +0100
@@ -68,11 +68,11 @@
 	    (fn (i,q,yet) => if q<0 then yet 
 			     else " "::Elem2String (i+lo)::"->"::State2String q::yet)
 	    (if fin then [" [Final]"] else nil)
-		(tab,0,NONE))
+		tab)
 	   
 	fun Dfa2String Elem2String tab =
 	   String.concat 
 	   (Vector.foldri
 	    (fn (q,row,yet) => State2String q::":"::Row2String Elem2String row::yet)
-	    nil (tab,0,NONE))
+	    nil tab)
     end
