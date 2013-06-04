--- ./src/CompileClassInfo.hs.orig	2012-04-18 17:05:10.000000000 +0200
+++ ./src/CompileClassInfo.hs	2013-05-04 03:12:14.541798377 +0200
@@ -45,6 +45,7 @@
                               , [ "    ) where"
                                 , ""
                                 , "import System.IO.Unsafe( unsafePerformIO )"
+                                , "import Foreign.C.Types ( CInt(..), CWchar(..), CDouble(..) )"
                                 , "import " ++ moduleRoot ++ moduleClassTypesName
                                 , "import " ++ moduleRoot ++ "WxcTypes"
                                 , "import " ++ moduleRoot ++ moduleClassesName
