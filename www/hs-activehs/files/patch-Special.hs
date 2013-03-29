--- ./Special.hs.orig	2013-02-12 20:23:46.000000000 +0100
+++ ./Special.hs	2013-02-18 19:59:53.000000000 +0100
@@ -1,4 +1,4 @@
-{-# LANGUAGE ScopedTypeVariables, OverloadedStrings, ViewPatterns, PatternGuards, NamedFieldPuns #-}
+{-# LANGUAGE ScopedTypeVariables, OverloadedStrings, ViewPatterns, PatternGuards, NamedFieldPuns, CPP #-}
 
 module Special
     ( SpecialTask (..), exerciseServer'
@@ -25,8 +25,9 @@
 import System.Directory (getTemporaryDirectory)
 
 import Control.Concurrent (threadDelay, forkIO, killThread)
---import Prelude hiding (catch)
-
+#if !MIN_VERSION_base(4,6,0)
+import Prelude hiding (catch)
+#endif
 
 ---------------------------------------------------------------
 
