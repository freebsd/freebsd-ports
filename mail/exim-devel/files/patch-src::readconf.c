--- src/readconf.c.orig	Fri Nov 23 17:31:21 2001
+++ src/readconf.c	Thu Dec 20 17:24:58 2001
@@ -1990,6 +1990,7 @@
 while (isalnum(*s) || *s == '_') s++;
 t = store_get(sizeof(tree_node) + s-ss);
 Ustrncpy(t->name, ss, s-ss);
+t->name[s-ss] = 0;
 while (isspace(*s)) s++;
 
 if (!tree_insertnode(anchorp, t))
