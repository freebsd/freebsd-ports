--- src/Network/Gitit/Layout.hs.orig	2023-07-10 14:38:47 UTC
+++ src/Network/Gitit/Layout.hs
@@ -123,7 +123,7 @@ filledPageTemplate base' cfg layout htmlContents templ
 
 
 exportBox :: String -> Config -> String -> Maybe String -> Html
-exportBox base' cfg page rev | not (isSourceCode page) =
+exportBox base' cfg page rev | exports cfg && not (isSourceCode page) =
   gui (base' ++ urlForPage page) ! [identifier "exportbox"] <<
     ([ textfield "revision" ! [thestyle "display: none;",
          value (fromJust rev)] | isJust rev ] ++
