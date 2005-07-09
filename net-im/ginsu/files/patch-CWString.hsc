--- CWString.hsc.orig	Wed Jul  6 02:16:58 2005
+++ CWString.hsc	Wed Jul  6 02:18:26 2005
@@ -36,6 +36,7 @@
 
 import Data.Bits
 import Foreign.C.String(withCString,CString,CStringLen,CWString,CWStringLen)
+import qualified Foreign.C.String as FS
 import Foreign.C.Types
 import Char
 import Foreign
@@ -270,12 +271,12 @@
 charIsRepresentable :: Char -> IO Bool
 charIsRepresentable ch = return $ isLatin1 ch
 
-withLCString = withCString
-withLCStringLen = withCStringLen
-newLCString = newCString
-newLCStringLen = newCStringLen
-peekLCString = peekCString
-peekLCStringLen = peekCStringLen
+withLCString = FS.withCString
+withLCStringLen = FS.withCStringLen
+newLCString = FS.newCString
+newLCStringLen = FS.newCStringLen
+peekLCString = FS.peekCString
+peekLCStringLen = FS.peekCStringLen
 
 #endif
 
