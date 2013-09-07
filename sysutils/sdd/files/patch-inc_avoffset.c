--- inc/avoffset.c.orig	2004-05-09 13:06:08.000000000 +0200
+++ inc/avoffset.c	2013-09-07 19:06:44.000000000 +0200
@@ -78,6 +78,9 @@ main(ac, av)
 	signal(SIGBUS, handler);
 #endif
 	signal(SIGSEGV, handler);
+#ifdef SIGILL
+	signal(SIGILL, handler);
+#endif
 
 	printf("/*\n");
 	printf(" * This file has been generated automatically\n");
