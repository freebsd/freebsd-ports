--- ./src/CompileClasses.hs.orig	2012-04-18 17:05:10.000000000 +0200
+++ ./src/CompileClasses.hs	2013-05-04 03:12:06.682675621 +0200
@@ -101,6 +101,7 @@
                                 , "import qualified Data.ByteString as B (ByteString, useAsCStringLen)"
                                 , "import qualified Data.ByteString.Lazy as LB (ByteString, length, unpack)"
                                 , "import System.IO.Unsafe( unsafePerformIO )"
+                                , "import Foreign.C.Types ( CInt(..), CWchar(..), CDouble(..) )"
                                 , "import " ++ moduleRoot ++ "WxcTypes"
                                 , "import " ++ moduleRoot ++ moduleClassTypesName
                                 , ""
