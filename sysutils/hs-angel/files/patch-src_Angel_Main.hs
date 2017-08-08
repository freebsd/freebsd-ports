--- src/Angel/Main.hs.orig	2015-07-17 04:07:17 UTC
+++ src/Angel/Main.hs
@@ -14,6 +14,7 @@ import Control.Concurrent.STM (TVar,
                                newTVarIO)
 import Control.Monad (forever)
 import Control.Monad.Reader
+import Data.Monoid
 import Options.Applicative
 import System.Environment (getArgs)
 import System.Exit (exitFailure,
