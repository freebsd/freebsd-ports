--- sigrot.c.orig	Sat Apr  1 17:17:32 2000
+++ sigrot.c	Sat Apr  1 17:18:06 2000
@@ -167,9 +167,10 @@
   inFile=fopen(Next,"r");
   if (inFile==NULL)
     next=1;
-  else
+  else {
     fscanf(inFile,"%d",&next);
-  fclose(inFile);
+    fclose(inFile);
+  }
   return next;
 }
 
