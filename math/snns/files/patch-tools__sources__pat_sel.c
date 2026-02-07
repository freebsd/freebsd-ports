--- tools/sources/pat_sel.c.orig	2008-04-21 16:56:08.000000000 +0900
+++ tools/sources/pat_sel.c	2012-10-24 04:43:51.000000000 +0900
@@ -58,7 +58,7 @@
 
   UPDATE   : 
 ******************************************************************************/
-void main (int argc, char *argv[])
+int main (int argc, char *argv[])
 { 
 
     int   pat_set, tot_pat_num;
@@ -88,7 +88,7 @@
     if(krui_loadNewPatterns(argv[2],&pat_set) != 0 /*KRERR_NO_ERROR*/){
 	fprintf(stderr, "error: can't read file %s\n", argv[2]) ;
 	fclose (in_no_file) ;
-	return ;
+	return 0;
     }
     tot_pat_num = krui_getNoOfPatterns();
 
