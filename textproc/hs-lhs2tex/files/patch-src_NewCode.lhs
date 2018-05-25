--- src/NewCode.lhs.orig	2018-04-25 07:08:55 UTC
+++ src/NewCode.lhs
@@ -13,6 +13,7 @@ way that is compatible with the @poly@ or @math@ forma
 > module NewCode                (  module NewCode  )
 > where
 >
+> import Prelude hiding ((<>))
 > import Control.Monad          (  (>=>) )
 > import Data.List              (  partition )
 >
