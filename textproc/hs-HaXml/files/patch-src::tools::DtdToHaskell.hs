--- src/tools/DtdToHaskell.hs.orig	Wed Aug 14 12:11:31 2002
+++ src/tools/DtdToHaskell.hs	Mon Sep  2 11:07:51 2002
@@ -29,8 +29,8 @@
       realname = if null name then mangle (trim inf) else mangle name
   in
   do hPutStrLn o ("module DTD_"++realname
-                  ++" where\n\nimport Text.Xml.HaXml.Xml2Haskell"
-                  ++" where\n\nimport Text.Xml.HaXml.OneOfN")
+                  ++" where\n\nimport Text.XML.HaXml.Xml2Haskell"
+                  ++"\nimport Text.XML.HaXml.OneOfN")
      hPutStrLn o "\n\n{-Type decls-}\n"
      (hPutStrLn o . render . vcat . map ppTypeDef) decls
      hPutStrLn o "\n\n{-Instance decls-}\n"
