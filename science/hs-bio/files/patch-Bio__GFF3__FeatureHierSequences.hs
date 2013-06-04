--- ./Bio/GFF3/FeatureHierSequences.hs.orig	2012-02-23 14:45:38.000000000 +0100
+++ ./Bio/GFF3/FeatureHierSequences.hs	2013-05-01 00:28:58.000000000 +0200
@@ -15,6 +15,7 @@
 import qualified Data.Map as M
 import Data.Maybe
 import qualified Data.Set as S
+import System.IO.Error (catchIOError)
 
 import Bio.Sequence.SeqData
 import Bio.Sequence.Fasta
@@ -72,7 +73,7 @@
                            return $ Seq seqname sequ Nothing
 
 catchIOErrors :: IO a -> ErrorT String IO a
-catchIOErrors m = ErrorT { runErrorT = liftM Right m `catch` (return . Left . show) }
+catchIOErrors m = ErrorT { runErrorT = liftM Right m `catchIOError` (return . Left . show) }
 
 runGFF :: FilePath -> (ErrorT String (Reader FeatureHierSequences) a) -> ErrorT String IO a
 runGFF gffname m = do gff <- catchIOErrors $ LBS.readFile gffname
