--- ./src/full/Agda/Utils/Pointer.hs.orig	2012-11-12 01:25:22.000000000 +0100
+++ ./src/full/Agda/Utils/Pointer.hs	2013-02-10 15:11:53.000000000 +0100
@@ -71,7 +71,7 @@
   compare = compare `on` ptrTag
 
 instance Hashable (Ptr a) where
-  hash = hash . ptrTag
+  hashWithSalt salt = hashWithSalt salt . ptrTag
 
 instance NFData (Ptr a) where
 
