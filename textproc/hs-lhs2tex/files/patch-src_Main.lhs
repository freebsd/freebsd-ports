--- src/Main.lhs.orig	2018-04-25 07:41:09 UTC
+++ src/Main.lhs
@@ -21,7 +21,7 @@
 > import Control.Monad.Error
 > import Control.Monad.State ( MonadState(..), modify )
 > import Control.Monad.Trans
-> import Prelude hiding ( getContents )
+> import Prelude hiding ( getContents, (<>) )
 >
 > import Version
 > import TeXCommands
