--- src/Text/XML/HaXml/Parse.hs.orig	Wed Aug 14 12:08:48 2002
+++ src/Text/XML/HaXml/Parse.hs	Sat Apr 12 10:31:06 2003
@@ -26,7 +26,7 @@
 
 
 #if defined(__NHC__)
-import IOExtras (unsafePerformIO)
+import NHC.IOExtras (unsafePerformIO)
 #endif
 #if defined(__HBC__)
 import UnsafePerformIO
