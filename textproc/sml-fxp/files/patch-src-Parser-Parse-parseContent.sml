diff -Naur src/Parser/Parse/parseContent.sml.orig src/Parser/Parse/parseContent.sml
--- src/Parser/Parse/parseContent.sml.orig	2003-10-09 09:47:56.000000000 -0500
+++ src/Parser/Parse/parseContent.sml	2003-10-17 14:26:30.000000000 -0500
@@ -587,7 +587,9 @@
 	       val _ = Array.update(dataBuffer,0,c0)
 
 	       fun data_hook (i,(a,q)) = 
-		  hookData(a,((!pos0,getPos q),Array.extract(dataBuffer,0,SOME i),false))
+		  hookData(a,((!pos0,getPos q),
+			      ArraySlice.vector(ArraySlice.slice(dataBuffer,0,SOME i)),
+			      false))
 	       fun takeOne (c,qE,i,aq as (a,q)) = 
 		  if i<DATA_BUFSIZE then (i+1,aq) before Array.update(dataBuffer,i,c)
 		  else let val a1 = data_hook(i,(a,qE))
