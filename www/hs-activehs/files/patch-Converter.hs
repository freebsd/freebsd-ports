--- Converter.hs.orig	2017-07-30 10:48:49 UTC
+++ Converter.hs
@@ -53,7 +53,7 @@ convert ghci args@(Args {magicname, sourcedir, gendir,
     object = sourcedir  </> what <.> "o"
 
 
-extract :: ParseMode -> Bool -> TaskChan -> Args -> Language -> Doc -> IO ()
+extract :: ParseMode -> Bool -> TaskChan -> Args -> Language -> Doc loc -> IO ()
 extract mode verbose ghci (Args {lang, templatedir, sourcedir, exercisedir, gendir, magicname}) what (Doc meta modu ss) = do
 
     writeEx (what <.> ext) [showEnv mode $ importsHiding []]
@@ -63,10 +63,9 @@ extract mode verbose ghci (Args {lang, templatedir, so
 
     writeFile' (gendir </> what <.> "xml") $ flip writeHtmlString (Pandoc meta $ concat ss')
       $ def
-        { writerStandalone      = True
-        , writerTableOfContents = True
+        { writerTableOfContents = True
         , writerSectionDivs     = True
-        , writerTemplate        = ht
+        , writerTemplate        = Just ht
         }
 
  where
@@ -95,10 +94,10 @@ extract mode verbose ghci (Args {lang, templatedir, so
         system s
 
     importsHiding funnames = case modu of
-        HaskellModule (HSyn.Module loc (HSyn.ModuleName modname) directives _ _ imps _) ->
+        HaskellModule (HSyn.Module loc (Just (HSyn.ModuleHead _ (HSyn.ModuleName _ modname) _ _)) directives imps _) ->
             HPty.prettyPrint $ 
-              HSyn.Module loc (HSyn.ModuleName "") directives Nothing Nothing
-                ([mkImport modname funnames, mkImport_ ('X':magicname) modname] ++ imps) []
+              HSyn.Module loc Nothing directives
+                ([mkImport loc modname funnames, mkImport_ loc ('X':magicname) modname] ++ imps) []
 --        _ -> error "error in Converter.extract"
 
     mkCodeBlock l =
@@ -237,27 +236,26 @@ showEnv HaskellMode prelude
     ++ prelude
     ++ "\n{-# LINE 1 \"input\" #-}\n"
 
-mkImport :: String -> [Name] -> HSyn.ImportDecl
-mkImport m d 
+mkImport :: loc -> String -> [Name] -> HSyn.ImportDecl loc
+mkImport loc m d 
     = HSyn.ImportDecl
-        { HSyn.importLoc = undefined
-        , HSyn.importModule = HSyn.ModuleName m
+        { HSyn.importModule = HSyn.ModuleName loc m
         , HSyn.importQualified = False
         , HSyn.importSrc = False
         , HSyn.importPkg = Nothing
         , HSyn.importAs = Nothing
-        , HSyn.importSpecs = Just (True, map (HSyn.IVar . mkName) d)
+        , HSyn.importSpecs = Just (HSyn.ImportSpecList loc True (map (HSyn.IVar loc . mkName loc) d))
         , HSyn.importSafe = False
         }
 
-mkName :: String -> HSyn.Name
-mkName n@(c:_)
-  | isLetter c = HSyn.Ident n
-mkName n       = HSyn.Symbol n
+mkName :: loc -> String -> HSyn.Name loc
+mkName loc n@(c:_)
+  | isLetter c = HSyn.Ident loc n
+mkName loc n   = HSyn.Symbol loc n
 
-mkImport_ :: String -> String -> HSyn.ImportDecl
-mkImport_ magic m 
-    = (mkImport m []) { HSyn.importQualified = True, HSyn.importAs = Just $ HSyn.ModuleName magic }
+mkImport_ :: loc -> String -> String -> HSyn.ImportDecl loc
+mkImport_ loc magic m 
+    = (mkImport loc m []) { HSyn.importQualified = True, HSyn.importAs = Just $ HSyn.ModuleName loc magic }
 
 ------------------
 
