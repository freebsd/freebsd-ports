--- du2ps.c.orig	Wed Mar 16 11:41:16 1994
+++ du2ps.c	Sun Mar 21 17:36:26 2004
@@ -57,7 +57,7 @@
 	for(; NULL != *mes; mes++) puts(*mes);
 }
 
-void
+int
 main(argc,argv)
 int argc;
 char **argv;
