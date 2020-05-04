--- src/Cryptol/ModuleSystem/Monad.hs.orig	2020-03-17 19:06:11 UTC
+++ src/Cryptol/ModuleSystem/Monad.hs
@@ -34,6 +34,7 @@ import           Cryptol.Utils.Ident (interactiveName,
 import           Cryptol.Utils.PP
 import           Cryptol.Utils.Logger(Logger)
 
+import qualified Control.Monad.Fail as Fail
 import Control.Monad.IO.Class
 import Control.Exception (IOException)
 import Data.Function (on)
@@ -325,6 +326,8 @@ instance Monad m => Monad (ModuleT m) where
 
   {-# INLINE (>>=) #-}
   m >>= f       = ModuleT (unModuleT m >>= unModuleT . f)
+
+instance Fail.MonadFail m => Fail.MonadFail (ModuleT m) where
   {-# INLINE fail #-}
   fail          = ModuleT . raise . OtherFailure
 
