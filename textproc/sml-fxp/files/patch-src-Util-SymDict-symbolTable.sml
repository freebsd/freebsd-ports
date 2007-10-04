diff -Naur src/Util/SymDict/symbolTable.sml.orig src/Util/SymDict/symbolTable.sml
--- src/Util/SymDict/symbolTable.sml.orig	2003-10-09 09:47:59.000000000 -0500
+++ src/Util/SymDict/symbolTable.sml	2003-10-17 14:03:39.000000000 -0500
@@ -219,7 +219,7 @@
 		  val _ = Array.update(newTab,i,key)
 	       in ()
 	       end
-	    val _ = Array.appi addToNew (!tab,0,NONE)
+	    val _ = Array.appi addToNew (!tab)
 
 	    val _ = tab   := newTab
 	    val _ = hash  := newHash
@@ -300,15 +300,15 @@
       (* extract the contents of a symbol table to a vector.                *)
       (*--------------------------------------------------------------------*)
       fun extractSymTable({count,tab,...}:SymTable) = 
-	 Array.extract(!tab,0,SOME(!count))
+	 ArraySlice.vector(ArraySlice.slice(!tab,0,SOME(!count)))
 
       (*--------------------------------------------------------------------*)
       (* print the contents of the symbol table.                            *)
       (*--------------------------------------------------------------------*)
       fun printSymTable ({desc,tab,count,...}:SymTable) = 
 	 (print (desc^" table:\n");
-	  Array.appi 
+	  ArraySlice.appi 
 	  (fn (n,key) =>
 	   print ("  "^Int.toString n^": "^Key.toString key^"\n")) 
-	  (!tab,0,SOME (!count))) 
+	  (ArraySlice.slice(!tab,0,SOME (!count))))
    end
