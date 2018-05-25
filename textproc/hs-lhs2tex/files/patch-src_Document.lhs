--- src/Document.lhs.orig	2018-04-25 07:05:53 UTC
+++ src/Document.lhs
@@ -9,6 +9,7 @@
 
 %endif
 
+> import Prelude hiding ((<>))
 > infixr 5 {-"\enskip"-} <>  -- same fixity as `|++|'
 
 The pretty printer generate documents of type |Doc|.
