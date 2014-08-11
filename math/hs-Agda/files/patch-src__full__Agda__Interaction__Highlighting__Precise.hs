--- ./src/full/Agda/Interaction/Highlighting/Precise.hs.orig	2014-07-29 19:41:41.000000000 +0100
+++ ./src/full/Agda/Interaction/Highlighting/Precise.hs	2014-08-10 11:30:01.000000000 +0100
@@ -40,7 +40,7 @@
 import Data.Monoid
 import Control.Applicative ((<$>), (<*>))
 import Control.Monad
-import Agda.Utils.QuickCheck
+import Agda.Utils.QuickCheck hiding (ranges)
 import Data.Map (Map)
 import qualified Data.Map as Map
 import Data.Typeable (Typeable)
