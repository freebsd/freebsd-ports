--- out.c.orig	1996-06-04 13:37:00 UTC
+++ out.c
@@ -143,7 +143,7 @@ void	print_body(struct data *d, struct m
 #endif
     }
   d->offset = d->bodystart;
-  while ((len = getline(d)) != 0)
+  while ((len = get_line(d)) != 0)
     {
       line->end = 0;
       append_data(line, (d->contents + d->offset), len, MED_BUF);
