--- src/Size.agda.orig	2014-11-14 23:18:11 UTC
+++ src/Size.agda
@@ -6,13 +6,8 @@
 
 module Size where
 
-postulate
-  Size   : Set
-  Size<_ : Size → Set
-  ↑_     : Size → Size
-  ∞      : Size
-
-{-# BUILTIN SIZE    Size   #-}
-{-# BUILTIN SIZELT  Size<_ #-}
-{-# BUILTIN SIZESUC ↑_     #-}
-{-# BUILTIN SIZEINF ∞      #-}
+{-# BUILTIN SIZEUNIV SizeUniv #-}  --  sort SizeUniv
+{-# BUILTIN SIZE     Size     #-}  --  Size   : SizeUniv
+{-# BUILTIN SIZELT   Size<_   #-}  --  Size<_ : Size → SizeUniv
+{-# BUILTIN SIZESUC  ↑_       #-}  --  ↑_     : Size → Size
+{-# BUILTIN SIZEINF  ∞        #-}  --  ∞      : Size
