--- ./agent/auto_nlist.c.orig	2012-10-09 18:28:58.000000000 -0400
+++ ./agent/auto_nlist.c	2013-04-10 14:26:21.000000000 -0400
@@ -56,6 +56,7 @@
         static char *n_name = NULL;
 #endif
         *ptr = (struct autonlist *) malloc(sizeof(struct autonlist));
+                               bzero(*ptr, sizeof(struct autonlist));
         it = *ptr;
         it->left = 0;
         it->right = 0;
