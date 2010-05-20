--- ./Bio/Alignment/BlastXML.hs.orig	2009-06-16 12:30:17.000000000 +0200
+++ ./Bio/Alignment/BlastXML.hs	2010-05-20 12:08:16.000000000 +0200
@@ -20,6 +20,8 @@
 import Control.Parallel
 import Data.List (isPrefixOf)
 
+type STag = Tag String
+
 -- | Parse BLAST results in XML format
 readXML :: FilePath -> IO [BlastResult]
 readXML fp = do 
@@ -38,7 +40,7 @@
                   in  rest `par` first : if null rest then [] else breaks p rest
 breaks _ []     = []
 
-getFrom :: [Tag] -> String -> String
+getFrom :: [STag] -> String -> String
 getFrom list tag = let xs = sections (isTagOpenName tag) list 
                    in if null xs || null (head xs) || (null . drop 1 . head) xs 
                       then error ("Couldn't find tag '"++show tag++"' in\n"++showSome list)
@@ -47,11 +49,11 @@
                              x -> error ("Unexpeced tag: "++ show x)
 
 -- Use pattern match since 'length' is strict, defeating the purpose.
-showSome :: [Tag] -> String
+showSome :: [STag] -> String
 showSome a@(_:_:_:_:_:_:_) = (init . show . take 5 $ a)++" ... ]"
 showSome a                 = show a
 
-xml2br :: [Tag] -> [[Tag]] -> BlastResult
+xml2br :: [STag] -> [[STag]] -> BlastResult
 xml2br h is = BlastResult { blastprogram = get "BlastOutput_program"
                           , blastversion = bv
                           , blastdate = bd 
@@ -64,7 +66,7 @@
     where (bv,bd) = B.break (=='[') $ get "BlastOutput_version"
           get = B.pack . getFrom h
 
-iter2rec :: [[Tag]] -> BlastRecord
+iter2rec :: [[STag]] -> BlastRecord
 iter2rec (i:hs) = BlastRecord 
               { query = B.pack $ get "Iteration_query-def"
               , qlength = read $ get "Iteration_query-len"
@@ -73,7 +75,7 @@
     where get = getFrom i
 iter2rec [] = error "iter2rec: got empty list of sections!"
 
-hit2hit :: [Tag] -> BlastHit
+hit2hit :: [STag] -> BlastHit
 hit2hit hs = BlastHit 
              { subject = B.pack $ get "Hit_def"
              , slength = read $ get "Hit_len"
@@ -82,7 +84,7 @@
     where get = getFrom hs
 
 
-hsp2match :: [Tag] -> BlastMatch
+hsp2match :: [STag] -> BlastMatch
 hsp2match ms = BlastMatch
                { bits   = read $ get "Hsp_bit-score"
                , e_val  = read $ get "Hsp_evalue"
