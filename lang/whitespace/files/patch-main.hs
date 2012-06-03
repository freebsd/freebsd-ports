--- ./main.hs.orig	2003-03-31 17:33:44.000000000 +0200
+++ ./main.hs	2012-05-12 21:52:07.000000000 +0200
@@ -26,7 +26,7 @@
 import VM
 import Tokens
 
-import System(getArgs)
+import System.Environment (getArgs)
 
 main :: IO ()
 main = do
