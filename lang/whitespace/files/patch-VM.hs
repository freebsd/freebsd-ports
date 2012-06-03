--- ./VM.hs.orig	2004-05-04 19:10:41.000000000 +0200
+++ ./VM.hs	2012-05-12 21:52:19.000000000 +0200
@@ -1,6 +1,6 @@
 module VM where
 
-import IO
+import System.IO
 
 {- Stack machine for running whitespace programs -}
 
