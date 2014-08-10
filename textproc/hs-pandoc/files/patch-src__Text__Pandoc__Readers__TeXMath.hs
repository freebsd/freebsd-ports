--- ./src/Text/Pandoc/Readers/TeXMath.hs.orig	2014-05-15 00:07:52.000000000 +0200
+++ ./src/Text/Pandoc/Readers/TeXMath.hs	2014-07-29 12:58:00.000000000 +0200
@@ -30,7 +30,7 @@
 module Text.Pandoc.Readers.TeXMath ( readTeXMath, readTeXMath' ) where
 
 import Text.Pandoc.Definition
-import Text.TeXMath
+import Text.TeXMath ( texMathToPandoc, DisplayType(DisplayBlock, DisplayInline) )
 
 -- | Converts a raw TeX math formula to a list of 'Pandoc' inlines.
 -- Defaults to raw formula between @$@ or @$$@ characters if entire formula
