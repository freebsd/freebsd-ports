--- ./Simple.hs.orig	2013-02-12 20:23:45.000000000 +0100
+++ ./Simple.hs	2013-02-18 19:59:53.000000000 +0100
@@ -1,4 +1,4 @@
-{-# LANGUAGE ExistentialQuantification, ScopedTypeVariables, PatternGuards, FlexibleContexts #-}
+{-# LANGUAGE ExistentialQuantification, ScopedTypeVariables, PatternGuards, FlexibleContexts, CPP #-}
 
 module Simple
     ( Task (..), TaskChan
@@ -23,7 +23,9 @@
 import Control.Monad (when, forever)
 import Control.Monad.Error (MonadError, catchError)
 import Data.List (isPrefixOf)
---import Prelude hiding (catch)
+#if !MIN_VERSION_base(4,6,0)
+import Prelude hiding (catch)
+#endif
 
 -------------------------
 
