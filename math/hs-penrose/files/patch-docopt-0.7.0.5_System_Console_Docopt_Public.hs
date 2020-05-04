--- docopt-0.7.0.5/System/Console/Docopt/Public.hs.orig	2020-04-11 09:34:12 UTC
+++ docopt-0.7.0.5/System/Console/Docopt/Public.hs
@@ -192,7 +192,7 @@ isPresentM args o = return $ isPresent args o
 {-# DEPRECATED getFirstArg "Use 'getAllArgs' instead" #-}
 getFirstArg :: Monad m => Arguments -> Option -> m String
 getFirstArg args opt =
-  let failure = fail $ "no argument given: " ++ show opt
+  let failure = error $ "no argument given: " ++ show opt
   in  case opt `M.lookup` args of
         Nothing  -> failure
         Just val -> case val of
