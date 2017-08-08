--- Setup.hs.orig	2017-04-28 17:39:58 UTC
+++ Setup.hs
@@ -90,7 +90,6 @@ myConfHook (pkg0, pbi) flags = do
 
     let libbi' = libbi
           { extraLibDirs   = extraLibDirs   libbi ++ [wxcDirectory]
-          , extraLibs      = extraLibs      libbi ++ ["wxc"]
           , PD.includeDirs = PD.includeDirs libbi ++ case glIncludeDirs of
                                                          ('-':'I':v) -> [v];
                                                          _           -> []
