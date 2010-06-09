--- ./src/Text/XML/HXT/Parser/TagSoup.hs.orig	2010-03-15 13:38:36.000000000 +0100
+++ ./src/Text/XML/HXT/Parser/TagSoup.hs	2010-06-07 05:27:36.000000000 +0200
@@ -240,8 +240,8 @@
 
 -- own entity lookup to prevent problems with &amp; and tagsoup hack for IE
 
-lookupEntity	:: Bool -> Bool -> String -> Tags
-lookupEntity withWarnings _asHtml e0@('#':e)
+lookupEntity	:: Bool -> Bool -> (String, Bool) -> Tags
+lookupEntity withWarnings _asHtml (e0@('#':e), b)
     = case lookupNumericEntity e of
       Just c  -> [ TagText [c] ]
       Nothing -> ( TagText $ "&" ++ e0 ++ ";") :
@@ -249,7 +249,7 @@
 		 then [TagWarning $ "illegal char reference: &" ++ e ++ ";"]
 		 else []
 
-lookupEntity withWarnings asHtml e
+lookupEntity withWarnings asHtml (e, b)
     = case (lookup e entities) of
       Just x  -> [TagText [toEnum x]]
       Nothing -> (TagText $ "&" ++ e ++ ";") :
@@ -266,7 +266,7 @@
     | null r	= (s,                   r)
     | otherwise	= ("&" ++ s ++ [';'|b], r)
     where
-    (TagText s) : r = lookupEntity withWarnings asHtml e
+    (TagText s) : r = lookupEntity withWarnings asHtml (e, b)
 
 -- ----------------------------------------
 {-
