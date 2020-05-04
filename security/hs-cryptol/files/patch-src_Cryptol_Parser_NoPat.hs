--- src/Cryptol/Parser/NoPat.hs.orig	2001-09-09 01:46:40 UTC
+++ src/Cryptol/Parser/NoPat.hs
@@ -542,7 +542,6 @@ instance Functor NoPatM where fmap = liftM
 instance Applicative NoPatM where pure = return; (<*>) = ap
 instance Monad NoPatM where
   return x  = M (return x)
-  fail x    = M (fail x)
   M x >>= k = M (x >>= unM . k)
 
 
