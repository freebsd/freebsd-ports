--- src/Typewriter.lhs.orig	2018-04-25 07:07:53 UTC
+++ src/Typewriter.lhs
@@ -7,6 +7,7 @@
 > module Typewriter             (  module Typewriter  )
 > where
 >
+> import Prelude hiding ((<>))
 > import Control.Monad
 >
 > import Verbatim ( trim, expand )
