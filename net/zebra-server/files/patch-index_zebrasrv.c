--- ./index/zebrasrv.c.orig	2013-10-27 11:58:33.890944518 +0100
+++ ./index/zebrasrv.c	2013-10-27 11:59:27.837331279 +0100
@@ -247,7 +247,7 @@
         case Z_Term_general:
             term->which = Z_Term_general;
             term->u.general = odr_malloc(r->stream, sizeof(*term->u.general));
-            term->u.general->size = term->u.general->len = len;
+            term->u.general->len = len;
             term->u.general->buf = odr_malloc(r->stream, len);
             memcpy(term->u.general->buf, outbuf, len);
             break;
