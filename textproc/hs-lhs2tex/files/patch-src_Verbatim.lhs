--- src/Verbatim.lhs.orig	2018-04-25 07:07:15 UTC
+++ src/Verbatim.lhs
@@ -7,6 +7,7 @@
 > module Verbatim               (  module Verbatim  )
 > where
 >
+> import Prelude hiding ((<>))
 > import Control.Arrow          (  (>>>) )
 > import Data.Char
 > import Data.List              (  intersperse )
