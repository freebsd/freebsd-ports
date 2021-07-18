--- _cabal_deps/hasql-1.4.2/library/Hasql/Private/IO.hs.orig	2020-03-21 17:55:07 UTC
+++ _cabal_deps/hasql-1.4.2/library/Hasql/Private/IO.hs
@@ -157,9 +157,7 @@ sendParametricStatement ::
   IO (Either CommandError ())
 sendParametricStatement connection integerDatetimes registry template encoder prepared params =
   {-# SCC "sendParametricStatement" #-} 
-  if prepared
-    then sendPreparedParametricStatement connection registry integerDatetimes template encoder params
-    else sendUnpreparedParametricStatement connection integerDatetimes template encoder params
+  sendUnpreparedParametricStatement connection integerDatetimes template encoder params
 
 {-# INLINE sendNonparametricStatement #-}
 sendNonparametricStatement :: LibPQ.Connection -> ByteString -> IO (Either CommandError ())
