--- ./Converter.hs.orig	2013-02-12 20:23:45.000000000 +0100
+++ ./Converter.hs	2013-05-28 16:20:35.000000000 +0200
@@ -249,8 +249,8 @@
 
 mkName :: String -> HSyn.Name
 mkName n@(c:_)
-    | isSymbol c = HSyn.Symbol n
-mkName n = HSyn.Ident n
+  | isLetter c = HSyn.Ident n
+mkName n       = HSyn.Symbol n
 
 mkImport_ :: String -> String -> HSyn.ImportDecl
 mkImport_ magic m 
