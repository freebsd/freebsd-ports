diff -Naur src/Util/SymDict/dict.sml.orig src/Util/SymDict/dict.sml
--- src/Util/SymDict/dict.sml.orig	2003-10-09 09:47:59.000000000 -0500
+++ src/Util/SymDict/dict.sml	2003-10-17 13:57:44.000000000 -0500
@@ -230,7 +230,7 @@
                in ()
                end
          in 
-	    Array.appi addTo (oldTab,0,NONE)
+	    Array.appi addTo oldTab
          end
 
       (*--------------------------------------------------------------------*)
@@ -316,8 +316,8 @@
       (*--------------------------------------------------------------------*)
       fun printDict X2String ({desc,tab,count,...}:'a Dict) = 
          (print (desc^" dictionary:\n");
-          Array.appi 
+          ArraySlice.appi 
           (fn (n,(key,value)) =>
            print ("  "^Int.toString n^": "^Key.toString key^" = "^X2String value^"\n")) 
-          (!tab,0,SOME (!count))) 
+          (ArraySlice.slice(!tab,0,SOME (!count))))
    end
