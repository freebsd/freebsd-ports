--- ./Network/CGI/Protocol.hs.orig	2014-02-04 09:00:24.000000000 +0100
+++ ./Network/CGI/Protocol.hs	2014-07-13 18:20:00.000000000 +0200
@@ -1,3 +1,4 @@
+{-# LANGUAGE DeriveDataTypeable #-}
 -----------------------------------------------------------------------------
 -- |
 -- Module      :  Network.CGI.Protocol
@@ -44,7 +45,7 @@
 import qualified Data.ByteString.Lazy.Char8 as BS
 import Data.ByteString.Lazy.Char8 (ByteString)
 
-import Data.Typeable (Typeable(..), mkTyConApp, mkTyCon)
+import Data.Typeable
 
 import Network.CGI.Header
 import Network.CGI.Multipart
@@ -72,9 +73,6 @@
                }
     deriving (Show)
 
-instance Typeable CGIResult where
-    typeOf _ = mkTyConApp (mkTyCon "Network.CGI.Protocol.CGIResult") []
-
 -- | The value of an input parameter, and some metadata.
 data Input = Input {
                     inputValue :: ByteString,
@@ -90,7 +88,7 @@
 -- | The result of a CGI program.
 data CGIResult = CGIOutput ByteString
                | CGINothing
-                 deriving (Show, Read, Eq, Ord)
+                 deriving (Show, Read, Eq, Ord, Typeable)
 
 --
 -- * Running CGI actions
