--- linclass.c.orig	2010-05-05 08:55:55.000000000 -0400
+++ linclass.c	2011-10-06 05:11:23.000000000 -0400
@@ -62,7 +62,7 @@
   uint32_t i, j;
   int len;
   int recognized;
-  int exitflag = 0;
+  int exitflag = 1;
   int verb;
   int binary_problem;
   int output_type;
@@ -101,6 +101,8 @@
   feat_idx = NULL;
   W = NULL;
   W0 = 0;
+  input_fname = NULL;
+  model_fname = NULL;
   output_fname = NULL;
   nClassErrors = NULL;
   nClass = NULL;
@@ -275,6 +277,7 @@
   if(fgets(line,LIBSLF_MAXLINELEN, fid) == NULL ) 
   {
     fprintf(stderr,"Empty example file.\n");
+    fclose(fid);
     goto clean_up;
   }
   else
@@ -312,6 +315,7 @@
     if( tmp_nCols != nCols)
     {
       fprintf(stderr,"Error: Model file contains lines with different number of colums.\n");
+      fclose(fid);
       goto clean_up;
     }
 
@@ -340,6 +344,7 @@
     if(W == NULL)
     {
       fprintf(stderr,"Not enough memory for vector W.\n");
+      fclose(fid);
       goto clean_up;
     }
 
@@ -355,6 +360,7 @@
       if(fgets(line,LIBSLF_MAXLINELEN, fid) == NULL ) 
       {
         fprintf(stderr,"Model file corrupted.\n");
+	fclose(fid);
         goto clean_up;
       }
 
@@ -364,6 +370,7 @@
       if(val == 0 && begptr == endptr)
       {
         fprintf(stderr,"Model file corrupted.\n");
+	fclose(fid);
         goto clean_up;
       }
 
@@ -388,6 +395,7 @@
     if(W == NULL)
     {
       fprintf(stderr,"Not enough memory for matrix W.\n");
+      fclose(fid);
       goto clean_up;
     }
 
@@ -403,6 +411,7 @@
       if(fgets(line,LIBSLF_MAXLINELEN, fid) == NULL ) 
       {
         fprintf(stderr,"Model file corrupted.\n");
+	fclose(fid);
         goto clean_up;
       }
 
@@ -414,6 +423,7 @@
         if(val == 0 && begptr == endptr)
         {
           fprintf(stderr,"Model file corrupted.\n");
+	  fclose(fid);
           goto clean_up;
         }
         begptr = endptr;
@@ -458,7 +468,7 @@
   else
   {
     fout = fopen(output_fname, "w+");
-    if(fid == NULL) {
+    if(fout == NULL) {
       fprintf(stderr,"Cannot open output file.\n");
       perror("fopen error ");
       fclose(fid);
@@ -478,6 +488,9 @@
   if(nClassErrors == NULL)
   {
     fprintf(stderr,"Not enough memory for vector nClassError.\n");
+    fclose(fid);
+    if(output_fname != NULL)
+      fclose(fout);
     goto clean_up;
   }
 
@@ -485,6 +498,9 @@
   if(nClass == NULL)
   {
     fprintf(stderr,"Not enough memory for vector nClass.\n");
+    fclose(fid);
+    if(output_fname != NULL)
+      fclose(fout);
     goto clean_up;
   }
   
@@ -505,6 +521,9 @@
       {
          fprintf(stderr,"Parsing error on line %ld .\n", line_cnt);
          fprintf(stderr,"Probably defective input file.\n");
+	 fclose(fid);
+	 if(output_fname != NULL)
+	   fclose(fout);
          goto clean_up;
       }
 
@@ -612,12 +631,16 @@
 
 
   fclose(fid);
-  fclose(fout);
+  if(output_fname != NULL)
+    fclose(fout);
 
-  exitflag = 1;
+  exitflag = 0;
   
 clean_up:
 
+  free(input_fname);
+  free(model_fname);
+  free(output_fname);
   free(W);
   free(line);
   free(feat_val);
