--- agent/auto_nlist.c.orig	Sun Feb 29 21:24:25 2004
+++ agent/auto_nlist.c	Sun Feb 29 21:24:43 2004
@@ -57,6 +57,7 @@
     }
     if (*ptr == 0) {
         *ptr = (struct autonlist *) malloc(sizeof(struct autonlist));
+	memset(*ptr, 0, sizeof(struct autonlist));
         it = *ptr;
         it->left = 0;
         it->right = 0;
