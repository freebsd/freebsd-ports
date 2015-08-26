--- src/cache.c.orig	2007-06-26 06:58:30 UTC
+++ src/cache.c
@@ -122,7 +122,7 @@ cache_init(void)
   jconfig_set();
   j = jconfig_getone("jwhois", "cachefile");
   if (!j)
-    cfname = LOCALSTATEDIR "/jwhois.db";
+    cfname = LOCALSTATEDIR "/jwhois";
   else
     cfname = j->value;
 
