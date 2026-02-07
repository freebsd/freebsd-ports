--- src/Network/Gitit/Util.hs.orig	2001-09-09 01:46:40 UTC
+++ src/Network/Gitit/Util.hs
@@ -115,6 +115,7 @@ parsePageType s =
        "latex"        -> (LaTeX,False)
        "latex+lhs"    -> (LaTeX,True)
        "org"          -> (Org,False)
+       "docbook"      -> (DocBook,False)
        "mediawiki"    -> (MediaWiki,False)
        x              -> error $ "Unknown page type: " ++ x
 
