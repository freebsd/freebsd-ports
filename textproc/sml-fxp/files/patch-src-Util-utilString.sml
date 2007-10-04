diff -Naur src/Util/utilString.sml.orig src/Util/utilString.sml
--- src/Util/utilString.sml.orig	2003-10-09 09:47:58.000000000 -0500
+++ src/Util/utilString.sml	2003-10-17 13:38:53.000000000 -0500
@@ -230,6 +230,9 @@
 	 if Vector.length vec=0 then pre^post
 	 else String.concat
 	    (pre::X2String(Vector.sub(vec,0))::
-	     Vector.foldri (fn (_,x,yet) => sep::X2String x::yet) [post] (vec,1,NONE))
+	     VectorSlice.foldri
+		 (fn (_,x,yet) => sep::X2String x::yet)
+		 [post]
+		 (VectorSlice.slice (vec,1,NONE)))
       fun Vector2String X2String vec = Vector2xString ("#[",",","]") X2String vec
    end
