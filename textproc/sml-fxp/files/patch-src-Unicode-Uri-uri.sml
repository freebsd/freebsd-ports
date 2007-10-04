--- src/Unicode/Uri/uri.sml.orig	Mon May 28 15:04:18 2007
+++ src/Unicode/Uri/uri.sml	Mon May 28 15:05:32 2007
@@ -50,6 +50,8 @@
 
       val slash = "/"
 
+      fun substringAll s = Substring.substring(s, 0, String.size s)
+
       fun uriSuffix s =
 	 let fun search i = if i<0 then NONE else case String.sub(s,i) 
 						    of #"." => SOME i
@@ -154,7 +156,7 @@
 
       fun convertCommand str (src,dst) =
 	 let 
-	    val s = Substring.all str
+	    val s = substringAll str
 	    fun doit ss s = 
 	       if Substring.isEmpty s then ss
 	       else let val (sl,sr) = Substring.splitr (fn c => #"%"<>c) s
@@ -162,12 +164,12 @@
 		       else let val sl' =  Substring.trimr 1 sl
 			    in case Substring.first sr
 				 of SOME #"1" => let val sr' = Substring.triml 1 sr
-						 in doit (Substring.all src::sr'::ss) sl'
+						 in doit (substringAll src::sr'::ss) sl'
 						 end
 				  | SOME #"2" => let val sr' = Substring.triml 1 sr
-						 in doit (Substring.all dst::sr'::ss) sl'
+						 in doit (substringAll dst::sr'::ss) sl'
 						 end
-				  | _ => doit (Substring.all "%"::sr::ss) sl'
+				  | _ => doit (substringAll "%"::sr::ss) sl'
 			    end
 		    end
 	    val ss = doit nil s
