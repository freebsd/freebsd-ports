--- s2s/out.c.orig	2012-08-22 08:03:58.000000000 +0200
+++ s2s/out.c	2013-06-13 23:25:13.528682146 +0200
@@ -627,7 +627,7 @@
             nad_free(pkt->nad);
         free(pkt);
 
-        return;
+        return 0;
     }
 
     /* new route key */
