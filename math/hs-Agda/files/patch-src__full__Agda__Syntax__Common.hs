--- ./src/full/Agda/Syntax/Common.hs.orig	2012-11-12 01:25:21.000000000 +0100
+++ ./src/full/Agda/Syntax/Common.hs	2013-02-10 15:12:42.000000000 +0100
@@ -272,8 +272,8 @@
   fromEnum (NameId n _) = fromIntegral n
 
 instance Hashable NameId where
-  {-# INLINE hash #-}
-  hash (NameId n m) = hash (n, m)
+  {-# INLINE hashWithSalt #-}
+  hashWithSalt salt (NameId n m) = hashWithSalt salt (n, m)
 
 newtype Constr a = Constr a
 
