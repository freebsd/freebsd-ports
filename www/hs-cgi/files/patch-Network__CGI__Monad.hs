--- ./Network/CGI/Monad.hs.orig	2014-02-04 09:00:24.000000000 +0100
+++ ./Network/CGI/Monad.hs	2014-07-13 18:20:00.000000000 +0200
@@ -1,4 +1,4 @@
-{-# OPTIONS_GHC -fglasgow-exts #-}
+{-# LANGUAGE DeriveDataTypeable #-}
 -----------------------------------------------------------------------------
 -- |
 -- Module      :  Network.CGI.Monad
@@ -40,8 +40,7 @@
 import Control.Monad.Reader (ReaderT(..), asks)
 import Control.Monad.Writer (WriterT(..), tell)
 import Control.Monad.Trans (MonadTrans, MonadIO, liftIO, lift)
-import Data.Typeable (Typeable(..), Typeable1(..), 
-                      mkTyConApp, mkTyCon)
+import Data.Typeable
 
 import Network.CGI.Protocol
 
@@ -55,10 +54,7 @@
 
 -- | The CGIT monad transformer.
 newtype CGIT m a = CGIT { unCGIT :: ReaderT CGIRequest (WriterT Headers m) a }
-
-instance (Typeable1 m, Typeable a) => Typeable (CGIT m a) where
-    typeOf _ = mkTyConApp (mkTyCon "Network.CGI.Monad.CGIT") 
-                [typeOf1 (undefined :: m a), typeOf (undefined :: a)]
+  deriving Typeable
 
 instance (Functor m, Monad m) => Functor (CGIT m) where
     fmap f c = CGIT (fmap f (unCGIT c))
