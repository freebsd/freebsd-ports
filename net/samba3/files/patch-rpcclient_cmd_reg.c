--- rpcclient/cmd_reg.c.orig	Sun Apr  4 09:37:28 2004
+++ rpcclient/cmd_reg.c	Thu May 20 14:18:36 2004
@@ -905,7 +905,11 @@
 	int opt;
 
 	*msg = 0;
-	optind = 0; /* TODO: test if this hack works on other systems too --simo */
+#ifdef HAVE_OPTRESET
+	optreset = optind = 1;
+#else
+	optind = 0;
+#endif
 
 	while ((opt = getopt(argc, argv, "m:t:rf")) != EOF)
 	{
