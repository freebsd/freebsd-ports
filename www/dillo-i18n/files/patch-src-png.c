--- src/png.c.orig	2005-10-27 18:20:14.000000000 +0200
+++ src/png.c	2010-03-29 21:23:10.000000000 +0200
@@ -355,7 +355,7 @@
             return;            /* need MORE data */
          }
          /* check the image signature - DON'T update ipbufstart! */
-         if (!png_check_sig(png->ipbuf, DATASIZE)) {
+         if (png_sig_cmp(png->ipbuf, 0, DATASIZE)) {
             /* you lied to me about it being a PNG image */
             png->state = IS_finished;
             break;
