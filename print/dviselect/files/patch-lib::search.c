--- lib/search.c~	Wed Nov 15 13:19:58 1989
+++ lib/search.c	Wed Dec 13 22:53:51 2006
@@ -72,7 +72,7 @@
 	s->s_space = 10;	/* initially, room for 10 objects */
 	s->s_n = 0;		/* and none in the table */
 	if ((s->s_data = malloc(s->s_space * dsize)) == 0) {
-		free((char *) s); (char *) s = 0;
+		free((char *) s); s = 0;
 		return (0);
 	}
 	return (s);
