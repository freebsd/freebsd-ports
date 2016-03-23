--- Converter.hs.orig	2013-02-12 19:23:45 UTC
+++ Converter.hs
@@ -28,7 +28,7 @@ import System.Directory (getTemporaryDir
 
 import Control.Monad
 import Data.List
-import Data.Char
+import Data.Char hiding (Format)
 
 ----------------------------------
 
@@ -206,7 +206,7 @@ preprocessForSlides x = case span (not .
 ------------------------------------
 
 rawHtml :: String -> Block
-rawHtml x = RawBlock "html" x
+rawHtml x = RawBlock (Format "html") x
 
 showBlockSimple :: Language -> String -> String -> Int -> String -> [Block]
 
@@ -244,13 +244,14 @@ mkImport m d 
         , HSyn.importSrc = False
         , HSyn.importPkg = Nothing
         , HSyn.importAs = Nothing
-        , HSyn.importSpecs = Just (True, map (HSyn.IVar . mkName) d)
+        , HSyn.importSpecs = Just (True, map (HSyn.IVar HSyn.NoNamespace . mkName) d)
+        , HSyn.importSafe = False
         }
 
 mkName :: String -> HSyn.Name
 mkName n@(c:_)
-    | isSymbol c = HSyn.Symbol n
-mkName n = HSyn.Ident n
+  | isLetter c = HSyn.Ident n
+mkName n       = HSyn.Symbol n
 
 mkImport_ :: String -> String -> HSyn.ImportDecl
 mkImport_ magic m 
