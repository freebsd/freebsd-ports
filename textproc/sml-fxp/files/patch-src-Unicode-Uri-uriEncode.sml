diff -Naur src/Unicode/Uri/uriEncode.sml.orig src/Unicode/Uri/uriEncode.sml
--- src/Unicode/Uri/uriEncode.sml.orig	2003-10-09 09:47:57.000000000 -0500
+++ src/Unicode/Uri/uriEncode.sml	2003-10-17 13:52:57.000000000 -0500
@@ -73,7 +73,7 @@
 						   in c2::c1:: #"%"::s
 						   end) 
 			      s (encodeCharUtf8 c)) 
-	    nil (cv,0,NONE)
+	    nil cv
 	 in String.implode (rev revd)
 	 end
 
@@ -85,7 +85,7 @@
 				 else let val (c1,c2) = Byte2Cc (Char2Byte c)
 				      in c2::c1:: #"%"::s
 				      end)) 
-	    nil (cv,0,NONE)
+	    nil cv
 	 in String.implode (rev revd)
 	 end
 
