--- pgpkey.c.orig	2014-03-12 17:03:44.000000000 +0100
+++ pgpkey.c	2015-04-13 17:50:05.000000000 +0200
@@ -985,13 +985,13 @@
       pgp_remove_key (&matches, k);
 
     pgp_free_key (&matches);
-    if (!p[l-1])
+    if (l && !p[l-1])
       p[l-1] = '!';
     return k;
   }
 
 out:
-  if (!p[l-1])
+  if (l && !p[l-1])
     p[l-1] = '!';
   return NULL;
 }
