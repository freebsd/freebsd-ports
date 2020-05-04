--- src/Cryptol/Parser/ParserUtils.hs.orig	2001-09-09 01:46:40 UTC
+++ src/Cryptol/Parser/ParserUtils.hs
@@ -139,7 +139,6 @@ instance Applicative ParseM where
 
 instance Monad ParseM where
   return a  = P (\_ _ s -> Right (a,s))
-  fail s    = panic "[Parser] fail" [s]
   m >>= k   = P (\cfg p s1 -> case unP m cfg p s1 of
                             Left e       -> Left e
                             Right (a,s2) -> unP (k a) cfg p s2)
