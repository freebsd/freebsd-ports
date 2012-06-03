--- ./src/full/Agda/Compiler/MAlonzo/Compiler.hs.orig	2012-03-12 11:09:33.000000000 +0100
+++ ./src/full/Agda/Compiler/MAlonzo/Compiler.hs	2012-04-08 22:51:55.000000000 +0200
@@ -466,7 +466,7 @@
   ]
   where
     parse = HS.parseWithMode
-              HS.defaultParseMode{HS.extensions = [HS.ExplicitForall]}
+              HS.defaultParseMode{HS.extensions = [HS.ExplicitForAll]}
 
     ok (HS.ParseOk d)   = d
     ok HS.ParseFailed{} = __IMPOSSIBLE__
