--- src/Cryptol/Eval/Monad.hs.orig	2001-09-09 01:46:40 UTC
+++ src/Cryptol/Eval/Monad.hs
@@ -38,6 +38,7 @@ module Cryptol.Eval.Monad
 
 import           Control.DeepSeq
 import           Control.Monad
+import qualified Control.Monad.Fail as Fail
 import           Control.Monad.Fix
 import           Control.Monad.IO.Class
 import           Data.IORef
@@ -164,9 +165,11 @@ instance Applicative Eval where
   {-# INLINE pure #-}
   {-# INLINE (<*>) #-}
 
+instance Fail.MonadFail Eval where
+  fail x = Thunk (\_ -> fail x)
+
 instance Monad Eval where
   return = Ready
-  fail x = Thunk (\_ -> fail x)
   (>>=)  = evalBind
   {-# INLINE return #-}
   {-# INLINE (>>=) #-}
