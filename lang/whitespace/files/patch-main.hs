--- main.hs.orig	2003-03-31 15:33:44 UTC
+++ main.hs
@@ -26,7 +26,7 @@ import Input
 import VM
 import Tokens
 
-import System(getArgs)
+import System.Environment (getArgs)
 
 main :: IO ()
 main = do
