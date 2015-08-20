--- Parse.hs.orig	2013-02-12 19:23:45 UTC
+++ Parse.hs
@@ -72,12 +72,13 @@ mainParse :: ParseMode -> FilePath -> IO
 mainParse mode s = do
     c <- readFile s
     case readMarkdown pState . unlines . concatMap preprocess . lines $ c of
-        Pandoc meta (CodeBlock ("",["sourceCode","literate","haskell"],[]) h: blocks) -> do
+        Right (Pandoc meta (CodeBlock ("",["sourceCode","literate","haskell"],[]) h: blocks)) -> do
             header <- parseModule mode $ h
             fmap (Doc meta header) $ collectTests mode $ map ({-highlight . -}interpreter . Text) blocks
-        Pandoc meta blocks -> do
+        Right (Pandoc meta blocks) -> do
             header <- parseModule mode $ "module Unknown where"
             fmap (Doc meta header) $ collectTests mode $ map ({-highlight . -}interpreter . Text) blocks
+        Left err -> fail $ "readMarkdown: " ++ show err
     where
         parseModule :: ParseMode -> String -> IO Module
         parseModule HaskellMode m = case HPar.parseModuleWithMode HPar.defaultParseMode m of
@@ -137,7 +138,7 @@ processHaskellLines isExercise l_ = retu
 
     getFName (HPar.ParseOk x) = case x of
         HSyn.TypeSig _ a _                       -> map printName a
-        HSyn.PatBind _ (HSyn.PVar a) _ _ _       -> [printName a]
+        HSyn.PatBind _ (HSyn.PVar a) _ _         -> [printName a]
         HSyn.FunBind (HSyn.Match _ a _ _ _ _ :_) -> [printName a]
         HSyn.TypeDecl _ a _ _                    -> [printName a]
         HSyn.DataDecl _ _ _ a _ x _              -> printName a: [printName n | HSyn.QualConDecl _ _ _ y<-x, n <- getN y]
