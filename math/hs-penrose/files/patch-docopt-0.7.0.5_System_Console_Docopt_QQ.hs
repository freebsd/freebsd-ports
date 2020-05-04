--- docopt-0.7.0.5/System/Console/Docopt/QQ.hs.orig	2016-11-10 15:48:52 UTC
+++ docopt-0.7.0.5/System/Console/Docopt/QQ.hs
@@ -56,7 +56,7 @@ docopt = QuasiQuoter { quoteExp  = docoptExp
                      , quotePat  = unsupported "Pattern"
                      , quoteType = unsupported "Type"
                      }
-    where unsupported = fail . (++ " context unsupported")
+    where unsupported = error . (++ " context unsupported")
 
 -- | Same as 'docopt', but parses the given file instead of a literal
 -- string.
