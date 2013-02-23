--- docs/tools/build-stdlib.c.orig	2013-02-22 07:56:59.781081590 -0500
+++ docs/tools/build-stdlib.c	2013-02-22 07:56:21.000000000 -0500
@@ -9,7 +9,7 @@
 #define true 1
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 struct Item
@@ -25,7 +25,7 @@
     struct Item *SortItemListNames(struct Item *list);
 int IncludeManualFile(FILE *fout,char *file);
 
-    
+int
 main(int argc, char *argv[])
 
 { FILE *fin,*fout = NULL;
@@ -35,7 +35,7 @@
 if ((fin = fopen(argv[1],"r")) == NULL)
    {
    printf("Could not open the %s file\n", argv[1]);
-   return;
+   return 1;
    }
 
    
@@ -67,7 +67,7 @@
       if ((fout = fopen(name,"w")) == NULL)
          {
          printf("Could not open output file %s\n",name);
-         return;
+         return 1;
          }
 
       fprintf(fout,"%s",buffer);
@@ -92,7 +92,7 @@
 if ((fout = fopen("CfengineStdLibrary.texinfo","w")) == NULL)
    {
    printf("Could not open the CfengineStdLibrary.texinfo file\n");
-   return;
+   return 1;
    }
 
 IncludeManualFile(fout,"preamble.texinfo");
@@ -131,7 +131,7 @@
 if ((fp = fopen(file,"r")) == NULL)
    {
    printf("Could not read %s\n",file);
-   return;
+   return 1;
    }
 
 while(!feof(fp))
