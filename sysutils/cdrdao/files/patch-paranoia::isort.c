--- paranoia/isort.c.orig	Sun Oct  6 20:53:56 2002
+++ paranoia/isort.c	Fri Dec 27 18:54:38 2002
@@ -22,9 +22,9 @@
   ret->size=-1;
   ret->maxsize=size;
 
-  ret->head=calloc(65536,sizeof(sort_link **));
+  ret->head=calloc(65536,sizeof(sort_link *));
   ret->bucketusage=malloc(65536*sizeof(long));
-  ret->revindex=calloc(size,sizeof(sort_link *));
+  ret->revindex=calloc(size,sizeof(sort_link));
   ret->lastbucket=0;
 
   return(ret);
