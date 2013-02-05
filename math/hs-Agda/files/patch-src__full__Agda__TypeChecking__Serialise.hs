--- ./src/full/Agda/TypeChecking/Serialise.hs.orig	2012-03-12 11:09:33.000000000 +0100
+++ ./src/full/Agda/TypeChecking/Serialise.hs	2013-02-05 04:30:03.000000000 +0100
@@ -119,7 +119,7 @@
 -- | With direct access to the internals of 'TypeRep' this instance
 -- could presumably be improved.
 instance Hashable TypeRep' where
-  hash = hash . show . unTypeRep'
+  hashWithSalt n = hashWithSalt n . show . unTypeRep'
 
 data St = St
   { nodeE     :: !(Array Int32 Node)
