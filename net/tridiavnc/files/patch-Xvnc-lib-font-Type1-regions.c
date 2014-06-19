--- Xvnc/lib/font/Type1/regions.c.orig	2000-04-12 11:18:28.000000000 -0700
+++ Xvnc/lib/font/Type1/regions.c	2013-10-30 23:15:05.000000000 -0700
@@ -1355,7 +1355,7 @@
  
        beg = left->link;
        if (beg == right)
-               return;
+               return(0);
  
        for (p = beg; p != right; p = p->link) {
                if (p->link == NULL && right != NULL)
