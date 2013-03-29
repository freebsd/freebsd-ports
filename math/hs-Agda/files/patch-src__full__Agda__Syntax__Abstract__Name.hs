--- ./src/full/Agda/Syntax/Abstract/Name.hs.orig	2012-11-12 01:25:21.000000000 +0100
+++ ./src/full/Agda/Syntax/Abstract/Name.hs	2013-02-10 15:14:44.000000000 +0100
@@ -239,8 +239,8 @@
   show x = show (nameConcrete x) -- ++ "|" ++ show (nameId x)
 
 instance Hashable Name where
-  {-# INLINE hash #-}
-  hash = hash . nameId
+  {-# INLINE hashWithSalt #-}
+  hashWithSalt salt = hashWithSalt salt . nameId
 
 instance Show QName where
   show q = concat $ intersperse "." $ map show $ qnameToList q
@@ -255,8 +255,8 @@
   compare = compare `on` qnameName
 
 instance Hashable QName where
-  {-# INLINE hash #-}
-  hash = hash . qnameName
+  {-# INLINE hashWithSalt #-}
+  hashWithSalt salt = hashWithSalt salt . qnameName
 
 instance HasRange Name where
   getRange = getRange . nameConcrete
