--- ./src/Control/Category/Dual.hs.orig	2013-06-20 22:09:11.000000000 +0200
+++ ./src/Control/Category/Dual.hs	2014-07-13 17:56:00.000000000 +0200
@@ -1,4 +1,4 @@
-{-# LANGUAGE TypeOperators, FlexibleContexts #-}
+{-# LANGUAGE TypeOperators, FlexibleContexts, DeriveDataTypeable #-}
 {-# LANGUAGE CPP #-}
 #if defined(__GLASGOW_HASKELL__) && __GLASGOW_HASKELL__ >= 702
 {-# LANGUAGE Trustworthy #-}
@@ -24,50 +24,11 @@
 
 import Prelude (undefined,const,error)
 import Control.Category
-
-#ifdef __GLASGOW_HASKELL__
-import Data.Data (Data(..), mkDataType, DataType, mkConstr, Constr, constrIndex, Fixity(..))
-#if MIN_VERSION_base(4,4,0)
-import Data.Typeable (Typeable2(..), TyCon, mkTyCon3, mkTyConApp, gcast1)
-#else
-import Data.Typeable (Typeable2(..), TyCon, mkTyCon, mkTyConApp, gcast1)
-#endif
-#endif
+import Data.Typeable
 
 data Dual k a b = Dual { runDual :: k b a }
+  deriving Typeable
 
 instance Category k => Category (Dual k) where
   id = Dual id
   Dual f . Dual g = Dual (g . f)
-
-#ifdef __GLASGOW_HASKELL__
-instance Typeable2 k => Typeable2 (Dual k) where
-  typeOf2 tfab = mkTyConApp dataTyCon [typeOf2 (undefined `asDualArgsType` tfab)]
-    where asDualArgsType :: f b a -> t f a b -> f b a
-          asDualArgsType = const
-
-dataTyCon :: TyCon
-#if MIN_VERSION_base(4,4,0)
-dataTyCon = mkTyCon3 "categories" "Control.Category.Dual" "Dual"
-#else
-dataTyCon = mkTyCon "Control.Category.Dual.Dual"
-#endif
-{-# NOINLINE dataTyCon #-}
-
-dualConstr :: Constr
-dualConstr = mkConstr dataDataType "Dual" [] Prefix
-{-# NOINLINE dualConstr #-}
-
-dataDataType :: DataType
-dataDataType = mkDataType "Control.Category.Dual.Dual" [dualConstr]
-{-# NOINLINE dataDataType #-}
-
-instance (Typeable2 k, Data a, Data b, Data (k b a)) => Data (Dual k a b) where
-  gfoldl f z (Dual a) = z Dual `f` a
-  toConstr _ = dualConstr
-  gunfold k z c = case constrIndex c of
-    1 -> k (z Dual)
-    _ -> error "gunfold"
-  dataTypeOf _ = dataDataType
-  dataCast1 f = gcast1 f
-#endif
