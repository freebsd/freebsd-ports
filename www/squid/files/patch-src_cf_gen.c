Index: src/cf_gen.c
===================================================================
RCS file: /cvsroot/squid/squid/src/cf_gen.c,v
retrieving revision 1.52
diff -u -p -r1.52 cf_gen.c
--- src/cf_gen.c	6 Sep 2007 09:33:36 -0000	1.52
+++ src/cf_gen.c	16 Sep 2007 17:57:24 -0000
@@ -183,7 +183,7 @@ main(int argc, char *argv[])
 	t = (Type *) xcalloc(1, sizeof(*t));
 	t->name = xstrdup(type);
 	while ((dep = strtok(NULL, WS)) != NULL) {
-	    TypeDep *d = (TypeDep *) xcalloc(1, sizeof(*dep));
+	    TypeDep *d = (TypeDep *) xcalloc(1, sizeof(*d));
 	    d->name = xstrdup(dep);
 	    d->next = t->depend;
 	    t->depend = d;
