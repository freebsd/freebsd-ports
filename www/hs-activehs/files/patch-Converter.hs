--- ./Converter.hs.orig	2013-02-12 20:23:45.000000000 +0100
+++ ./Converter.hs	2013-12-27 18:34:37.000000000 +0100
@@ -28,7 +28,7 @@
 
 import Control.Monad
 import Data.List
-import Data.Char
+import Data.Char hiding (Format)
 
 ----------------------------------
 
@@ -206,7 +206,7 @@
 ------------------------------------
 
 rawHtml :: String -> Block
-rawHtml x = RawBlock "html" x
+rawHtml x = RawBlock (Format "html") x
 
 showBlockSimple :: Language -> String -> String -> Int -> String -> [Block]
 
@@ -249,8 +249,8 @@
 
 mkName :: String -> HSyn.Name
 mkName n@(c:_)
-    | isSymbol c = HSyn.Symbol n
-mkName n = HSyn.Ident n
+  | isLetter c = HSyn.Ident n
+mkName n       = HSyn.Symbol n
 
 mkImport_ :: String -> String -> HSyn.ImportDecl
 mkImport_ magic m 
