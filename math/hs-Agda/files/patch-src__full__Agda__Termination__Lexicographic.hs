--- ./src/full/Agda/Termination/Lexicographic.hs.orig	2012-03-12 11:09:33.000000000 +0100
+++ ./src/full/Agda/Termination/Lexicographic.hs	2012-10-03 23:48:30.000000000 +0200
@@ -230,7 +230,7 @@
   , quickCheck' prop_fromDiagonals
   , quickCheck' prop_newBehaviour
   , quickCheckWith' stdArgs{ maxSuccess = 50
-                           , maxDiscard = 200
+                           , maxDiscardRatio = 200
                            , maxSize    = 20
                            }
                     prop_lexOrder
