--- x11-ssh-askpass.c.orig	2016-11-06 16:18:21.595954000 +0900
+++ x11-ssh-askpass.c	2016-11-06 16:20:39.207609000 +0900
@@ -764,6 +764,10 @@
    d->sizeHints->flags = 0;
    d->sizeHints->flags |= PPosition;
    d->sizeHints->flags |= PSize;
+   d->sizeHints->x = d->w3.w.x; 
+   d->sizeHints->y = d->w3.w.y;
+   d->sizeHints->width = d->w3.w.width;
+   d->sizeHints->height = d->w3.w.height;
    d->sizeHints->min_width = d->w3.w.width;
    d->sizeHints->min_height = d->w3.w.height;
    d->sizeHints->flags |= PMinSize;
