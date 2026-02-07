--- process.c.orig	Wed Apr  4 16:25:29 2007
+++ process.c	Wed Apr  4 16:26:49 2007
@@ -74,7 +74,7 @@
 		memset(z, 0, sizeof *z);
 		check_line(l);
 		z->line = l++;
-		(struct process *) p->priv = z;
+		p->priv = z;
 		z->proc = p;
 		if (*current){
 			z->next = *current;
