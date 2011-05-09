--- ./src/full/Agda/Utils/Generics.hs.orig	2011-02-20 16:43:52.000000000 +0100
+++ ./src/full/Agda/Utils/Generics.hs	2011-03-13 15:32:35.151924104 +0100
@@ -3,7 +3,7 @@
 -}
 module Agda.Utils.Generics where
 
-import Data.Generics
+import Data.Generics hiding (everythingBut)
 
 isString :: GenericQ Bool
 isString = mkQ False (const True :: String -> Bool)
