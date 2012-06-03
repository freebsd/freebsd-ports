--- ./Setup.hs.orig	2012-04-13 14:40:36.000000000 +0200
+++ ./Setup.hs	2012-05-13 20:41:08.000000000 +0200
@@ -66,7 +66,6 @@
 
     let libbi' = libbi
           { extraLibDirs = extraLibDirs libbi ++ [wxcDirectory]
-          , extraLibs    = extraLibs    libbi ++ ["wxc"]
           , ldOptions    = ldOptions    libbi ++ ["-Wl,-rpath," ++ wxcDirectory]  }
 
     let lib' = lib { libBuildInfo = libbi' }
