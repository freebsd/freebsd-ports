--- src/Cryptol/TypeCheck/Monad.hs.orig	2001-09-09 01:46:40 UTC
+++ src/Cryptol/TypeCheck/Monad.hs
@@ -278,7 +278,6 @@ instance A.Applicative InferM where
 
 instance Monad InferM where
   return x      = IM (return x)
-  fail x        = IM (fail x)
   IM m >>= f    = IM (m >>= unIM . f)
 
 instance MonadFix InferM where
@@ -835,7 +834,6 @@ instance A.Applicative KindM where
 
 instance Monad KindM where
   return x      = KM (return x)
-  fail x        = KM (fail x)
   KM m >>= k    = KM (m >>= unKM . k)
 
 
