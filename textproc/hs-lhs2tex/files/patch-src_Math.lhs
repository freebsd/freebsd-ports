--- src/Math.lhs.orig	2018-04-25 07:40:44 UTC
+++ src/Math.lhs
@@ -7,7 +7,7 @@
 > module Math                   (  module Math, substitute, number  )
 > where
 >
-> import Prelude hiding         (  lines )
+> import Prelude hiding         (  lines, (<>) )
 > import Data.List              (  partition )
 > import Numeric                (  showFFloat )
 > import Control.Applicative    (  many )
