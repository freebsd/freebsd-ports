--- t/gen-stat.c.orig	Sun May 21 04:19:35 2006
+++ t/gen-stat.c	Sun Jun 25 10:29:33 2006
@@ -13,11 +13,6 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
-#ifdef _HAVE_SYS_SYSMACROS_H
-# include <sys/sysmacros.h>
-#endif
-
-
 #undef P
 #undef CONCAT
 #undef CONCAT1
@@ -126,8 +121,9 @@
 
     *_shift=shift;
 
-    for(*_mask=0; mask=MASK(shift), f(mask) != 0; ++shift)
-	*_mask |= mask;
+    for(*_mask=0; mask=MASK(shift), shift < sizeof mask * 8; ++shift)
+     if ( f(mask) != 0 )
+	 *_mask |= mask;
 }
 
 
