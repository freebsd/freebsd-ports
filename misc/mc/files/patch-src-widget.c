--- src/widget.c.orig	Thu Dec 26 05:15:48 2002
+++ src/widget.c	Tue Jun 15 03:15:09 2004
@@ -607,7 +607,7 @@
 	if (!g->shown)
 	    printw ("%*s", gauge_len, "");
 	else {
-	    long percentage, columns;
+	    int percentage, columns;
 	    long total = g->max, done = g->current;
 	    
 	    if (total <= 0 || done < 0) {
@@ -1255,10 +1255,11 @@
 {
    int first = min (x_first, x_last);
    int last  = max (x_first, x_last);
+   size_t len = strlen (&in->buffer [last]) + 1;
 
    in->point = first;
    in->mark  = first;
-   strcpy (&in->buffer [first], &in->buffer [last]);
+   memmove (&in->buffer [first], &in->buffer [last], len);
    in->need_push = 1;
 }
 
