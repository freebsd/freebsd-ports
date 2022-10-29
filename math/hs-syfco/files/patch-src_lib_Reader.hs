--- src/lib/Reader.hs.orig	2022-10-28 19:22:32 UTC
+++ src/lib/Reader.hs
@@ -102,7 +102,7 @@ fromTLSF str =
   inferTypes >>=
 
   -- lift reader specification to global specification
-  \(s @ RD.Specification {..}) -> return
+  \(s@RD.Specification {..}) -> return
     Specification
       { source         = str
       , title          = fst title
