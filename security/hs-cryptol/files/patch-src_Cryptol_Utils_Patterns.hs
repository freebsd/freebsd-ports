--- src/Cryptol/Utils/Patterns.hs.orig	2001-09-09 01:46:40 UTC
+++ src/Cryptol/Utils/Patterns.hs
@@ -5,6 +5,7 @@
 module Cryptol.Utils.Patterns where
 
 import Control.Monad(liftM,liftM2,ap,MonadPlus(..),guard)
+import qualified Control.Monad.Fail as Fail
 import Control.Applicative(Alternative(..))
 
 newtype Match b = Match (forall r. r -> (b -> r) -> r)
@@ -17,10 +18,12 @@ instance Applicative Match where
   (<*>)  = ap
 
 instance Monad Match where
-  fail _ = empty
   Match m >>= f = Match $ \no yes -> m no $ \a ->
                                      let Match n = f a in
                                      n no yes
+
+instance Fail.MonadFail Match where
+  fail _ = empty
 
 instance Alternative Match where
   empty = Match $ \no _ -> no
