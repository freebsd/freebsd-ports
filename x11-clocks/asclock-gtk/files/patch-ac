--- config.c~	Fri Mar 26 16:38:29 1999
+++ config.c	Sat Jun 12 15:55:56 1999
@@ -52,14 +52,14 @@
       fprintf(stderr, "dir : %s\n", *cpp);
 
       if((dfd = opendir(*cpp)) == NULL)
-	  printf(" not found\n\n"); 
+	  printf(" not found\n"); 
       else {
 	while((dp = readdir(dfd)) != NULL)
 	  if ( dp->d_name[0]!='.' )
 	    printf("%s\n", dp->d_name);
         closedir(dfd);
       }
-      printf("\n\n");
+      printf("\n");
 
     }
 
