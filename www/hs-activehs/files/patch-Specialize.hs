--- ./Specialize.hs.orig	2013-02-12 19:23:45.000000000 +0000
+++ ./Specialize.hs	2013-08-28 17:32:07.000000000 +0100
@@ -15,7 +15,7 @@
 
 specialize :: String -> Either String (String, String)
 specialize a
-    = case parseTypeWithMode (defaultParseMode {extensions = [FlexibleContexts]}) a of
+    = case parseTypeWithMode (defaultParseMode {extensions = [EnableExtension FlexibleContexts]}) a of
         ParseFailed loc s -> Left $ show s
         ParseOk t -> let
 
