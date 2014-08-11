--- ./QuickCheck.hs.orig	2013-02-12 20:23:46.000000000 +0100
+++ ./QuickCheck.hs	2014-07-14 02:54:45.000000000 +0200
@@ -7,13 +7,14 @@
 import Logger
 import Qualify (qualify)
 import Hash
+import Specialize (specialize)
 
 import Test.QuickCheck hiding (Result)
 import qualified Test.QuickCheck.Property as QC
 
 import Data.Char (isLower)
 import Data.List (intercalate)
-import Control.Monad (join)
+import Control.Monad (join,forM)
 import Control.Concurrent.MVar
 
 ---------------------------------------
@@ -38,19 +39,24 @@
             return [Error True err]
         Right s_ -> do
             logStrMsg 3 (logger ch) $ "Qualified expressions: " ++ show s_
-
-            let ts = mkTestCases [(v,s,s') | ((v,s),s')<- zip testcases s_]
-            logStrMsg 3 (logger ch) $ "Test cases: " ++ ts
-            
             interp False m5 lang ch fn "" $ \a ->
-                do  liftIO $ logStrMsg 3 (logger ch) "Before interpretation"
+                do  ss <- forM (testcases `zip` s_) $ \((v,s1),s2) -> do
+                      ts1 <- typeOf s1
+                      ts2 <- typeOf s2
+                      let [x1,x2] = map fixType [(s1,ts1),(s2,ts2)]
+                      return $ mkTestCase (v,x1,x2)
+                    let ts = "[" ++ intercalate ", " ss ++ "]"
+                    liftIO $ logStrMsg 3 (logger ch) $ "Test cases: " ++ ts
+                    liftIO $ logStrMsg 3 (logger ch) "Before interpretation"
                     m <- interpret ts (as :: [TestCase])
                     liftIO $ logStrMsg 3 (logger ch) "After interpretation"
                     return $ qcs lang (logger ch) m
 
   where
-    mkTestCases ss 
-        = "[" ++ intercalate ", " (map mkTestCase ss) ++ "]"
+    fixType (s,t) =
+      case (specialize t) of
+        Right (st,_) | t /= st -> unwords [s, "::", st]
+        _ -> s
 
     mkTestCase (vars, s, s2)  
         = "TestCase (\\qcinner " 
