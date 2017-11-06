--- Parse.hs.orig	2017-07-30 10:48:49 UTC
+++ Parse.hs
@@ -17,6 +17,7 @@ import Text.Pandoc
 
 import qualified Language.Haskell.Exts.Parser as HPar
 import qualified Language.Haskell.Exts.Syntax as HSyn
+import qualified Language.Haskell.Exts.SrcLoc as HLoc
 
 import Data.List.Split (splitOn)
 import Data.List (tails, partition, groupBy)
@@ -30,15 +31,15 @@ import qualified Data.Set as Set
 data ParseMode = HaskellMode -- | AgdaMode
                  deriving (Show, Enum, Eq)
 
-data Module
-    = HaskellModule HSyn.Module
+data Module loc
+    = HaskellModule (HSyn.Module loc)
 --    | AgdaModule ASyn.Module
     deriving (Show)
 
-data Doc
+data Doc loc
     = Doc
         Meta{-title, author, date-}
-        Module{-module directives, module name, imports-}
+        (Module{-module directives, module name, imports-} loc)
         [BBlock]
         deriving (Show)
 
@@ -68,7 +69,7 @@ testCommandList = "EeFfH"
 
 -----------------------------------
 
-mainParse :: ParseMode -> FilePath -> IO Doc
+mainParse :: ParseMode -> FilePath -> IO (Doc HLoc.SrcSpanInfo)
 mainParse mode s = do
     c <- readFile s
     case readMarkdown pState . unlines . concatMap preprocess . lines $ c of
@@ -80,7 +81,7 @@ mainParse mode s = do
             fmap (Doc meta header) $ collectTests mode $ map ({-highlight . -}interpreter . Text) blocks
         Left err -> fail $ "readMarkdown: " ++ show err
     where
-        parseModule :: ParseMode -> String -> IO Module
+        parseModule :: ParseMode -> String -> IO (Module HLoc.SrcSpanInfo)
         parseModule HaskellMode m = case HPar.parseModuleWithMode HPar.defaultParseMode m of
             (HPar.ParseOk m) -> return $ HaskellModule m
             parseError       -> fail $ "parseHeader: " ++ show parseError
@@ -137,17 +138,17 @@ processHaskellLines isExercise l_ = return (concatMap 
     names = concatMap (getFName . snd) x
 
     getFName (HPar.ParseOk x) = case x of
-        HSyn.TypeSig _ a _                       -> map printName a
-        HSyn.PatBind _ (HSyn.PVar a) _ _         -> [printName a]
-        HSyn.FunBind (HSyn.Match _ a _ _ _ _ :_) -> [printName a]
-        HSyn.TypeDecl _ a _ _                    -> [printName a]
-        HSyn.DataDecl _ _ _ a _ x _              -> printName a: [printName n | HSyn.QualConDecl _ _ _ y<-x, n <- getN y]
-        _                                        -> []
+        HSyn.TypeSig _ a _                        -> map printName a
+        HSyn.PatBind _ (HSyn.PVar _ a) _ _        -> [printName a]
+        HSyn.FunBind _ ((HSyn.Match _ a _ _ _):_) -> [printName a]
+        HSyn.TypeDecl _ (HSyn.DHead _ a) _        -> [printName a]
+        HSyn.DataDecl _ _ _ (HSyn.DHead _ a) x _  -> printName a: [printName n | HSyn.QualConDecl _ _ _ y<-x, n <- getN y]
+        _                                         -> []
     getFName _ = []
 
-    getN (HSyn.ConDecl n _) = [n]
-    getN (HSyn.InfixConDecl _ n _) = [n]
-    getN (HSyn.RecDecl n l) = n: concatMap fst l
+    getN (HSyn.ConDecl _ n _) = [n]
+    getN (HSyn.InfixConDecl _ _ n _) = [n]
+    getN (HSyn.RecDecl _ n l) = n : concatMap (\(HSyn.FieldDecl _ xs _) -> xs) l
 
     isVisible (HPar.ParseOk (HSyn.TypeSig _ _ _)) = True
     isVisible (HPar.ParseOk (HSyn.InfixDecl _ _ _ _)) = True
@@ -181,6 +182,6 @@ parseQuickCheck :: String -> ([String], String)
 parseQuickCheck s = case splitOn ";;" s of
     l -> (init l, last l)
 
-printName :: HSyn.Name -> Name
-printName (HSyn.Ident x) = x
-printName (HSyn.Symbol x) = x
+printName :: HSyn.Name loc -> Name
+printName (HSyn.Ident _ x) = x
+printName (HSyn.Symbol _ x) = x
