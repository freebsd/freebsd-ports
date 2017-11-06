--- src/Text/Blaze/Renderer/XmlHtml.hs.orig	2017-05-19 10:38:07 UTC
+++ src/Text/Blaze/Renderer/XmlHtml.hs
@@ -58,22 +58,20 @@ renderNodes = go []
         (Element (getText tag) attrs (go [] content []) :)
     go attrs (CustomParent tag content) =
         (Element (fromChoiceStringText tag) attrs (go [] content []) :)
-    go attrs (Leaf tag _ _) =
+    go attrs (Leaf tag _ _ _) =
         (Element (getText tag) attrs [] :)
-    go attrs (CustomLeaf tag _) =
+    go attrs (CustomLeaf tag _ _) =
         (Element (fromChoiceStringText tag) attrs [] :)
     go attrs (AddAttribute key _ value content) =
         go ((getText key, fromChoiceStringText value) : attrs) content
     go attrs (AddCustomAttribute key value content) =
         go ((fromChoiceStringText key, fromChoiceStringText value) : attrs)
            content
-    go _ (Content content) = fromChoiceString content
-#if MIN_VERSION_blaze_markup(0,6,3)
-    go _ (TBI.Comment comment) =
+    go _ (Content content _) = fromChoiceString content
+    go _ (TBI.Comment comment _) =
         (X.Comment (fromChoiceStringText comment) :)
-#endif
     go attrs (Append h1 h2) = go attrs h1 . go attrs h2
-    go _ Empty = id
+    go _ (Empty _) = id
     {-# NOINLINE go #-}
 {-# INLINE renderNodes #-}
 
