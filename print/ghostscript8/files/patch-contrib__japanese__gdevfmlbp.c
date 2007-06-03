--- contrib/japanese/gdevfmlbp.c.orig	Thu Apr 26 01:27:24 2007
+++ contrib/japanese/gdevfmlbp.c	Tue May 15 16:49:03 2007
@@ -121,7 +121,7 @@
      height_inches >=  9.2 ? PAPER_SIZE_B5 :
      height_inches >=  7.6 ? PAPER_SIZE_A5 : PAPER_SIZE_HAGAKI), landscape);
 #ifdef	FMLBP_DEBUG
-  fprintf(stderr, "w=%d(%f) x h=%d(%f) -> %s\n",
+  dprintf5("w=%d(%f) x h=%d(%f) -> %s\n",
 	  dev->width, width_inches, dev->height, height_inches, paper);
 #endif/*FMLBP_DEBUG*/
   return paper;
