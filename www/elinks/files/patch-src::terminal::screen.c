--- src/terminal/screen.c	Sun Jan  4 02:07:50 2004
+++ src/terminal/screen.c	Fri Feb 20 11:43:54 2004
@@ -575,6 +575,9 @@ add_char256(struct string *screen, struc
 		register int x = 0;						\
 										\
 		for (; x < (term_)->width; x++, current++, pos++) {		\
+			if (y == (term_)->height - 1 &&				\
+			    x == (term_)->width - 1)				\
+				break;						\
 			if (compare_bg_color(pos->color, current->color)) {	\
 				/* No update for exact match. */		\
 				if (compare_fg_color(pos->color, current->color)\
