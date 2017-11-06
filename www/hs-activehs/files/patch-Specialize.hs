--- Specialize.hs.orig	2017-07-30 10:48:49 UTC
+++ Specialize.hs
@@ -23,32 +23,32 @@ specialize a
 
             in Right (prettyPrint t', prettyPrint t'')
 
-split :: Type -> ([(String, [String])], Type)
-split (TyForall Nothing l t) 
+split :: Type a -> ([(String, [String])], Type a)
+split (TyForall _ Nothing (Just (CxTuple _ l)) t)
     = ( map (\x -> (fst (head x), map snd x)) $ groupBy ((==) `on` fst) $ sort
-          [(v,s) | ClassA (UnQual (Ident s)) [TyVar (Ident v)]<-l]
+          [(v,s) | ClassA _ (UnQual _ (Ident _ s)) [TyVar _ (Ident _ v)]<-l]
       , t
       )
 split t 
     = ([], t)
 
-convert :: ([(String, [String])], Type) -> (Type, Type)
+convert :: ([(String, [String])], Type a) -> (Type a, Type a)
 convert (m, t) = (app True mm t, app False mm t)  where mm = map resolve m
 
-app :: Bool -> [(String, [[Char]])] -> Type -> Type
+app :: Bool -> [(String, [[Char]])] -> Type a -> Type a
 app b m t = f t where
-    f (TyFun a b) = TyFun (f a) (f b)
-    f (TyTuple bo l) = TyTuple bo $ map f l
-    f (TyList t) = TyList (f t)
-    f (TyParen t) = TyParen (f t)
-    f (TyApp x t) = TyApp (f x) (f t)
-    f (TyVar (Ident s)) = mkV $ head $ [y | (v,x)<-m, v==s, y<-ff  x] ++ ff allT
+    f (TyFun t a b) = TyFun t (f a) (f b)
+    f (TyTuple t bo l) = TyTuple t bo $ map f l
+    f (TyList x t) = TyList x (f t)
+    f (TyParen x t) = TyParen x (f t)
+    f (TyApp v x t) = TyApp v (f x) (f t)
+    f (TyVar v (Ident _ s)) = mkV v $ head $ [y | (v,x)<-m, v==s, y<-ff  x] ++ ff allT
     f t = t
 
     ff = if b then id else reverse
 
-mkV :: String -> Type
-mkV v = TyVar $ Ident v
+mkV :: a -> String -> Type a
+mkV x v = TyVar x $ Ident x v
 
 resolve :: (String, [String]) -> (String, [String])
 resolve (v, l) = (v, foldl1 intersect $ map res l)
