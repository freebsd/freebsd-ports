--- ./Simple.hs.orig	2013-02-12 20:23:45.000000000 +0100
+++ ./Simple.hs	2014-07-14 02:44:00.000000000 +0200
@@ -19,9 +19,10 @@
 import Control.Concurrent (forkIO)
 import Control.Concurrent.MVar (MVar, newEmptyMVar, takeMVar, putMVar)
 import Control.Concurrent.Chan (Chan, newChan, readChan, writeChan)
-import Control.Exception (SomeException, catch)
+import Control.Exception (SomeException)
+import qualified Control.Exception as CE
 import Control.Monad (when, forever)
-import Control.Monad.Error (MonadError, catchError)
+import Control.Monad.Catch (catch)
 import Data.List (isPrefixOf)
 --import Prelude hiding (catch)
 
@@ -42,7 +43,7 @@
     _ <- forkIO $ forever $ do
         logStrMsg 1 log "start interpreter"
         e <- runInterpreter (handleTask ch Nothing)
-              `catch` \(e :: SomeException) ->
+              `CE.catch` \(e :: SomeException) ->
                 return $ Left $ UnknownError "GHCi server died."
         case e of
             Left  e  -> logStrMsg 0 log $ "stop interpreter: " ++ show e
@@ -95,10 +96,10 @@
 fatal (NotAllowed _)  = False
 fatal _ = True
 
-catchError_fixed 
-    :: MonadError InterpreterError m 
+catchError_fixed
+    :: MonadInterpreter m
     => m a -> (InterpreterError -> m a) -> m a
-m `catchError_fixed` f = m `catchError` (f . fixError)
+m `catchError_fixed` f = m `catch` (f . fixError)
   where
     fixError (UnknownError s) 
         | Just x <- dropPrefix "GHC returned a result but said: [GhcError {errMsg =" s
