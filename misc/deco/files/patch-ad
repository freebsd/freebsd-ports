Index: dir.c
@@ -358,8 +358,10 @@
 
 	d->topfile = d->curfile = 0;
 
+	if (d->sort != SORTSKIP) {
 	compdir = d;
 	qsort ((char*)d->cat, (unsigned) d->num, sizeof (d->cat[0]), compfile);
+	}
 
 	if (! dirname) {
 		/* retag files, restore curfile */
