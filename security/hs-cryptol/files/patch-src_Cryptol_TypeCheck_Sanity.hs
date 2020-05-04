--- src/Cryptol/TypeCheck/Sanity.hs.orig	2001-09-09 01:46:40 UTC
+++ src/Cryptol/TypeCheck/Sanity.hs
@@ -467,7 +467,6 @@ instance A.Applicative TcM where
 
 instance Monad TcM where
   return a    = TcM (return a)
-  fail x      = TcM (fail x)
   TcM m >>= f = TcM (do a <- m
                         let TcM m1 = f a
                         m1)
