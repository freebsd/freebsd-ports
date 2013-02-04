--- tools/sources/pat_sel_simple.c.orig	2008-04-21 16:56:08.000000000 +0900
+++ tools/sources/pat_sel_simple.c	2012-10-24 04:33:30.000000000 +0900
@@ -168,7 +168,7 @@
 /* main program                                                               */
 /******************************************************************************/
 	  
-void main (int argc, char *argv[])
+int main (int argc, char *argv[])
 { 
   float  *output_pattern    ;
   float  *input_pattern     ;
@@ -188,28 +188,28 @@
   {  
     fprintf (stderr, "usage: %s <no_file> <in_pat_file> <out_pat_file>\n",
              argv[0]); 
-    return ;
+    return 0;
   }
 
   
   if ((in_no_file   = fopen(argv[1], "r")) == (FILE *) NULL) 
   { 
     fprintf(stderr, "error: can't read file %s\n", argv[1]) ;
-    return ;
+    return 0;
   }
   
   if ((in_pat_file  = fopen(argv[2], "r")) == (FILE *) NULL)
   { 
     fprintf(stderr, "error: can't read file %s\n", argv[2]) ;
     fclose (in_no_file) ;
-    return ;
+    return 0;
   }
 
   if ((out_pat_file = fopen(argv[3], "r")) != (FILE *) NULL)
   {
     fclose(out_pat_file) ;
     fprintf (stderr, "overwrite %s (y/n) ? ", argv[3]) ;
-    if (getc(stdin) != 'y') return ; 
+    if (getc(stdin) != 'y') return 0; 
   }
 
   if ((out_pat_file = fopen(argv[3], "w")) == (FILE *) NULL)
@@ -217,7 +217,7 @@
     fprintf(stderr, "error: can't create file %s\n", argv[3]) ;
     fclose (in_no_file)  ;
     fclose (in_pat_file) ;
-    return ;
+    return 0;
   }
 
   
