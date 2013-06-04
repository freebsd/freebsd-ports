--- ./src/haskell/Graphics/UI/WXCore/Events.hs.orig	2012-07-04 12:29:32.000000000 +0200
+++ ./src/haskell/Graphics/UI/WXCore/Events.hs	2013-05-04 03:24:48.030431193 +0200
@@ -239,6 +239,7 @@
 
 import Data.List( intersperse, findIndex )
 import System.Environment( getProgName, getArgs )
+import Foreign.C.Types ( CInt(..) )
 import Foreign.StablePtr
 import Foreign.Ptr
 import Foreign.C.String
