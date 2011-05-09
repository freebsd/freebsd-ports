--- ./src/full/Agda/Interaction/Highlighting/Generate.hs.orig	2011-02-20 16:43:52.000000000 +0100
+++ ./src/full/Agda/Interaction/Highlighting/Generate.hs	2011-03-13 15:37:48.951336040 +0100
@@ -37,7 +37,7 @@
 import Control.Monad.State
 import Control.Applicative
 import Data.Monoid
-import Data.Generics
+import Data.Generics hiding (everythingBut)
 import Data.Function
 import Agda.Utils.Generics
 import Agda.Utils.FileName
