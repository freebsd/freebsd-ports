--- src/MathPoly.lhs.orig	2018-04-25 07:08:26 UTC
+++ src/MathPoly.lhs
@@ -13,7 +13,7 @@ are subtle differences, and they will grow over time \
 > module MathPoly               (  module MathPoly, substitute, number  )
 > where
 >
-> import Prelude hiding         (  lines )
+> import Prelude hiding         (  lines, (<>) )
 > import Data.List              (  partition, nub, insert, sort, transpose )
 > import Numeric                (  showFFloat )
 > import Control.Applicative    (  many )
