--- src/mrss_free.c.orig	Mon Apr  2 20:54:41 2007
+++ src/mrss_free.c	Thu Apr 26 10:59:50 2007
@@ -202,9 +202,6 @@
       __mrss_free_item ((mrss_item_t *) old);
     }
 
-  if (mrss->c_locale)
-    freelocale (mrss->c_locale);
-
   if (mrss->allocated)
     free (mrss);
 }
