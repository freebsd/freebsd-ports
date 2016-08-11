--- Setup.hs.orig	2016-06-20 16:11:53 UTC
+++ Setup.hs
@@ -78,7 +78,6 @@ myConfHook (pkg0, pbi) flags = do
 
     let libbi' = libbi
           { extraLibDirs = extraLibDirs libbi ++ [wxcDirectory]
-          , extraLibs    = extraLibs    libbi ++ ["wxc"]
           , ldOptions    = ldOptions    libbi ++ ["-Wl,-rpath," ++ wxcDirectory]  }
 
     let lib' = lib { libBuildInfo = libbi' }
