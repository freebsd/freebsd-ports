--- src/cache.c.dist	Sun Dec 19 06:46:53 1999
+++ src/cache.c	Sat Jul 15 22:52:06 2000
@@ -119,7 +119,7 @@
   jconfig_set();
   j = jconfig_getone("jwhois", "cachefile");
   if (!j)
-    cfname = LOCALSTATEDIR "/jwhois.db";
+    cfname = LOCALSTATEDIR "/jwhois";
   else
     cfname = j->value;
 
