--- Qualify.hs.orig	2017-07-30 10:48:49 UTC
+++ Qualify.hs
@@ -21,44 +21,47 @@ qualify 
     -> String   -- ^ Haskell expression
     -> Either String String     -- ^ either the modified expression or an error
 qualify q ns x = case parseExpWithMode defaultParseMode x of
-    ParseOk y -> Right $ prettyPrint $ runReader (trExp y) ns
+    ParseOk y -> Right $ prettyPrint $ runReader (trExp proxy y) ns
     e         -> Left $ show e
- where 
-    trQName :: QName -> R QName
-    trQName y@(UnQual x) = do
-        b <- asks (printName x `elem`)
-        return $ if b then (Qual (ModuleName q) x) else y
-    trQName y = return y
+ where
+    proxy = error "qualify"
 
-    trExp :: Exp -> R Exp
-    trExp (Lambda loc pats e) = do
-        pats' <- tr pats
-        e' <- local (\\ vars pats) $ trExp e
+    trQName :: Data loc => loc -> QName loc -> R (QName loc)
+    trQName _ y@(UnQual loc x) = do
+        b <- asks (printName loc x `elem`)
+        return $ if b then (Qual loc (ModuleName loc q) x) else y
+    trQName _ y = return y
+
+    trExp :: Data loc => loc -> Exp loc -> R (Exp loc)
+    trExp _ (Lambda loc pats e) = do
+        pats' <- tr loc pats
+        e' <- local (\\ vars loc pats) $ trExp loc e
         return $ Lambda loc pats' e'
-    trExp (Let b e) = do
-        (b', e') <- local (\\ vars b) $ tr (b, e)
-        return $ Let b' e'
-    trExp x = gmapM tr x
+    trExp _ (Let loc b e) = do
+        (b', e') <- local (\\ vars loc b) $ tr loc (b, e)
+        return $ Let loc b' e'
+    trExp loc x = gmapM (tr loc) x
 
 {-
 Alt:
 Alt SrcLoc Pat GuardedAlts Binds
 -}
 
-    tr :: Data x => x -> R x
-    tr = everywhereM (mkM trQName) `extM` trExp
+    tr :: (Data loc, Data a) => loc -> a -> R a
+    tr loc = everywhereM (mkM (trQName loc)) `extM` (trExp loc)
 
-    vars :: Data a => a -> [String]
-    vars = map printName . everything (++) (mkQ [] patVars_)
+    vars :: (Typeable loc, Data a) => loc -> a -> [String]
+    vars loc = map (printName loc) . everything (++) (mkQ [] (patVars_ loc))
 
-    patVars_ :: Pat -> [Name]
-    patVars_ (PVar x) = [x]
-    patVars_ (PAsPat x _) = [x]
-    patVars_ (PNPlusK x _) = [x]
-    patVars_ _ = []
+    patVars_ :: loc -> Pat loc -> [Name loc]
+    patVars_ _ (PVar _ x) = [x]
+    patVars_ _ (PAsPat _ x _) = [x]
+    patVars_ _ (PNPlusK _ x _) = [x]
+    patVars_ _ _ = []
 
-    printName (Ident x) = x
-    printName (Symbol x) = x
+    printName :: loc -> Name loc -> String
+    printName _ (Ident _ x) = x
+    printName _ (Symbol _ x) = x
 
 {- !!!
 PatTypeSig SrcLoc Pat Type	
