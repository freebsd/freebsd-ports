--- lib/tfm.c~	Wed Nov 15 13:20:02 1989
+++ lib/tfm.c	Wed Dec 13 22:56:44 2006
@@ -63,16 +63,16 @@
 	
       bad:
 	if (t->t_ci != NULL) {
-	  free((char *) t->t_ci); (char *) t->t_ci = 0;
+	  free((char *) t->t_ci); t->t_ci = 0;
 	}
 	if (t->t_width != NULL) {
-	  free((char *) t->t_width); (char *) t->t_width = 0;
+	  free((char *) t->t_width); t->t_width = 0;
 	}
 	if (t->t_height != NULL) {
-	  free((char *) t->t_height); (char *) t->t_height = 0;
+	  free((char *) t->t_height); t->t_height = 0;
 	}
 	if (t->t_depth != NULL) {
-	  free((char *) t->t_depth); (char *) t->t_depth = 0;
+	  free((char *) t->t_depth); t->t_depth = 0;
 	}
 	return (-1);
       }
