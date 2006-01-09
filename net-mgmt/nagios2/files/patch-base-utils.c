--- base/utils.c.orig	Sat Dec 24 06:01:36 2005
+++ base/utils.c	Wed Dec 28 17:53:36 2005
@@ -4546,7 +4546,7 @@
 
 	use_embedded_perl=TRUE;
 
-	PERL_SYS_INIT3(&argc,embedding,&env);
+	PERL_SYS_INIT3(&argc,&embedding,&env);
 
 	if((my_perl=perl_alloc())==NULL){
 		use_embedded_perl=FALSE;
