--- source/rpcclient/cmd_reg.c.orig	Thu Nov 27 12:17:08 2003
+++ source/rpcclient/cmd_reg.c	Thu Nov 27 12:19:24 2003
@@ -900,6 +900,9 @@
 {
 	extern char *optarg;
 	extern int optind;
+#if	defined(__FreeBSD__)
+	extern int optreset;
+#endif
 	NTSTATUS result = NT_STATUS_UNSUCCESSFUL;
 	fstring msg;
 	uint32 timeout = 20;
@@ -907,7 +910,11 @@
 	int opt;
 
 	*msg = 0;
+#if	defined(__FreeBSD__)
+	optreset = optind = 1;
+#else
 	optind = 0; /* TODO: test if this hack works on other systems too --simo */
+#endif
 
 	while ((opt = getopt(argc, argv, "m:t:rf")) != EOF)
 	{
