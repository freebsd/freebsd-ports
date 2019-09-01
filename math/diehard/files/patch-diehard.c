--- diehard.c.orig	2019-09-01 17:00:11 UTC
+++ diehard.c
@@ -117,7 +117,7 @@ void diehard()

   ungetc(c, stdin);

-  gets(fn);
+  fgets(fn,100,stdin);
 
   puts("\n\t\tHERE ARE YOUR CHOICES:\n");
   puts("\t\t1   Birthday Spacings");
@@ -153,5 +153,5 @@ main()
 {
   diehard();
 
-   return;
+   return 0;
 }
