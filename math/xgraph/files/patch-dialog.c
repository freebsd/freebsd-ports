--- dialog.c.orig	2000-08-03 16:40:44 UTC
+++ dialog.c
@@ -702,7 +702,7 @@ xtb_frame *frame;		/* Returned frame */
     new_info->lines = (Window *) malloc((unsigned) (sizeof(Window) * E_LINES));
 
     lineptr = text;
-    while (getline(&lineptr, line)) {
+    while (get_line(&lineptr, line)) {
 	if (new_info->num_lines >= new_info->alloc_lines) {
 	    new_info->alloc_lines *= 2;
 	    new_info->lines = (Window *) realloc((char *) new_info->lines,
@@ -800,7 +800,7 @@ char *err_text;
 
 
 
-int getline(tptr, lptr)
+int get_line(tptr, lptr)
 char **tptr;
 char *lptr;
 /*
