--- ./tools/memory.c.orig	2012-03-26 14:46:05.000000000 +0200
+++ ./tools/memory.c	2014-01-08 14:13:28.000000000 +0100
@@ -165,7 +165,7 @@
 static void print_ptrs(char *msg)
 {  int bucket,i,n=0;
 
-   fprintf(stdout, msg);
+   fprintf(stdout, "msg\n");
 
    for(bucket=0; bucket<64; bucket++)
       for(i=0; i<phCnt[bucket]; i++)
