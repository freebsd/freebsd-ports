--- mpeg2play.c	1997/08/11 18:58:37	1.1
+++ mpeg2play.c	1997/08/11 19:07:22
@@ -335,7 +335,7 @@
   XmStringGetLtoR(((XmFileSelectionBoxCallbackStruct *)call_data)->value,
 		  XmSTRING_DEFAULT_CHARSET, &filename);
 
-  position = tell(base.infile);
+  position = lseek(base.infile, 0L, SEEK_CUR);
   fprintf(stderr, "pos: %d\n", position);
   fprintf(stderr, "output: %s\n", filename);
 
