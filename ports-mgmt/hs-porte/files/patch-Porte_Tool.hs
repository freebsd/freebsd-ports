--- Porte/Tool.hs.orig	2010-08-29 16:18:36 UTC
+++ Porte/Tool.hs
@@ -1,6 +1,6 @@
 module Porte.Tool(toolMain) where
 import System.Environment
-import System.Exit
+import System.Exit hiding (die)
 import Control.Monad
 import qualified Data.ByteString.Lazy.Char8 as B
 import qualified Porte.Ports      as P
