diff -u -r1.33 -r1.34
--- src/fcint.h	2003/03/05 05:52:31	1.33
+++ src/fcint.h	2003/03/12 22:15:39	1.34
@@ -338,7 +338,7 @@
 FcGlobalCacheDestroy (FcGlobalCache *cache);
 
 FcBool
-FcGlobalCacheCheckTime (FcGlobalCacheInfo *info);
+FcGlobalCacheCheckTime (const FcChar8*file, FcGlobalCacheInfo *info);
 
 void
 FcGlobalCacheReferenced (FcGlobalCache	    *cache,
