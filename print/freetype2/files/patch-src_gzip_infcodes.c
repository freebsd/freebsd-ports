--- src/gzip/infcodes.c.orig	Sat Jan 18 15:44:46 2003
+++ src/gzip/infcodes.c	Sat Jan 18 15:46:10 2003
@@ -196,8 +196,8 @@
       c->mode = COPY;
     case COPY:          /* o: copying bytes in window, waiting for space */
       f = q - c->sub.copy.dist;
-      while (f < s->window)             /* modulo window size-"while" instead */
-        f += s->end - s->window;        /* of "if" handles invalid distances */
+      if ((uInt)(q - s->window) < c->sub.copy.dist)
+	  f = s->end - (c->sub.copy.dist - (uInt)(q - s->window));
       while (c->len)
       {
         NEEDOUT
