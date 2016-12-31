--- configure.ml.orig	2016-01-20 16:52:18 UTC
+++ configure.ml
@@ -843,7 +843,7 @@ let strip =
 (** * md5sum command *)
 
 let md5sum =
-  if arch = "Darwin" then "md5 -q" else "md5sum"
+  if arch = "FreeBSD" then "md5 -q" else "md5sum"
 
 
 (** * Documentation : do we have latex, hevea, ... *)
