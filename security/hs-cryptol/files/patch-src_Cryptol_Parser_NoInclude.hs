--- src/Cryptol/Parser/NoInclude.hs.orig	2001-09-09 01:46:40 UTC
+++ src/Cryptol/Parser/NoInclude.hs
@@ -104,7 +104,6 @@ instance A.Applicative NoIncM where
 instance Monad NoIncM where
   return x = M (return x)
   m >>= f  = M (unM m >>= unM . f)
-  fail x   = M (fail x)
 
 -- | Raise an 'IncludeFailed' error.
 includeFailed :: Located FilePath -> NoIncM a
