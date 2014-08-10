--- ./src/Control/Categorical/Functor.hs.orig	2013-06-20 22:09:11.000000000 +0200
+++ ./src/Control/Categorical/Functor.hs	2014-07-13 17:57:00.000000000 +0200
@@ -2,7 +2,7 @@
 #if defined(__GLASGOW_HASKELL__) && __GLASGOW_HASKELL__ >= 702
 {-# LANGUAGE Trustworthy #-}
 #endif
-{-# LANGUAGE MultiParamTypeClasses, FunctionalDependencies, FlexibleContexts, UndecidableInstances, FlexibleInstances #-}
+{-# LANGUAGE MultiParamTypeClasses, FunctionalDependencies, FlexibleContexts, UndecidableInstances, FlexibleInstances, DeriveDataTypeable #-}
 -------------------------------------------------------------------------------------------
 -- |
 -- Module      : Control.Categorical.Functor
@@ -29,86 +29,12 @@
 import Control.Category
 import Prelude hiding (id, (.), Functor(..))
 import qualified Prelude
-#ifdef __GLASGOW_HASKELL__
-import Data.Data (Data(..), mkDataType, DataType, mkConstr, Constr, constrIndex, Fixity(..))
-#if MIN_VERSION_base(4,4,0)
-import Data.Typeable (Typeable1(..), TyCon, mkTyCon3, mkTyConApp, gcast1)
-#else
-import Data.Typeable (Typeable1(..), TyCon, mkTyCon, mkTyConApp, gcast1)
-#endif
-#endif
+import Data.Typeable
 
 -- TODO Data, Typeable
-newtype LiftedFunctor f a = LiftedFunctor (f a) deriving (Show, Read)
-
-#ifdef __GLASGOW_HASKELL__
-
-liftedTyCon :: TyCon
-#if MIN_VERSION_base(4,4,0)
-liftedTyCon = mkTyCon3 "categories" "Control.Categorical.Functor" "LiftedFunctor"
-#else
-liftedTyCon = mkTyCon "Control.Categorical.Functor.LiftedFunctor"
-#endif
-{-# NOINLINE liftedTyCon #-}
-
-liftedConstr :: Constr
-liftedConstr = mkConstr liftedDataType "LiftedFunctor" [] Prefix
-{-# NOINLINE liftedConstr #-}
-
-liftedDataType :: DataType
-liftedDataType = mkDataType "Control.Categorical.Fucntor.LiftedFunctor" [liftedConstr]
-{-# NOINLINE liftedDataType #-}
-
-instance Typeable1 f => Typeable1 (LiftedFunctor f) where
-  typeOf1 tfa = mkTyConApp liftedTyCon [typeOf1 (undefined `asArgsType` tfa)]
-    where asArgsType :: f a -> t f a -> f a
-          asArgsType = const
-
-instance (Typeable1 f, Data (f a), Data a) => Data (LiftedFunctor f a) where
-  gfoldl f z (LiftedFunctor a) = z LiftedFunctor `f` a
-  toConstr _ = liftedConstr
-  gunfold k z c = case constrIndex c of
-    1 -> k (z LiftedFunctor)
-    _ -> error "gunfold"
-  dataTypeOf _ = liftedDataType
-  dataCast1 f = gcast1 f
-#endif
-
-newtype LoweredFunctor f a = LoweredFunctor (f a) deriving (Show, Read)
-
-#ifdef __GLASGOW_HASKELL__
-
-loweredTyCon :: TyCon
-#if MIN_VERSION_base(4,4,0)
-loweredTyCon = mkTyCon3 "categories" "Control.Categorical.Functor" "LoweredFunctor"
-#else
-loweredTyCon = mkTyCon "Control.Categorical.Functor.LoweredFunctor"
-#endif
-{-# NOINLINE loweredTyCon #-}
-
-loweredConstr :: Constr
-loweredConstr = mkConstr loweredDataType "LoweredFunctor" [] Prefix
-{-# NOINLINE loweredConstr #-}
-
-loweredDataType :: DataType
-loweredDataType = mkDataType "Control.Categorical.Fucntor.LoweredFunctor" [loweredConstr]
-{-# NOINLINE loweredDataType #-}
-
-instance Typeable1 f => Typeable1 (LoweredFunctor f) where
-  typeOf1 tfa = mkTyConApp loweredTyCon [typeOf1 (undefined `asArgsType` tfa)]
-    where asArgsType :: f a -> t f a -> f a
-          asArgsType = const
-
-instance (Typeable1 f, Data (f a), Data a) => Data (LoweredFunctor f a) where
-  gfoldl f z (LoweredFunctor a) = z LoweredFunctor `f` a
-  toConstr _ = loweredConstr
-  gunfold k z c = case constrIndex c of
-    1 -> k (z LoweredFunctor)
-    _ -> error "gunfold"
-  dataTypeOf _ = loweredDataType
-  dataCast1 f = gcast1 f
+newtype LiftedFunctor f a = LiftedFunctor (f a) deriving (Show, Read, Typeable)
 
-#endif
+newtype LoweredFunctor f a = LoweredFunctor (f a) deriving (Show, Read, Typeable)
 
 class (Category r, Category t) => Functor f r t | f r -> t, f t -> r where
   fmap :: r a b -> t (f a) (f b)
