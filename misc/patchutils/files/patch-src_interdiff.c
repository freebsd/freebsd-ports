--- src/interdiff.c.orig	2025-08-22 00:37:41.000000000 -0700
+++ src/interdiff.c	2025-09-11 13:06:21.163966000 -0700
@@ -832,9 +832,9 @@
 
 	fflush (NULL);
 	char *argv[2 + num_diff_opts + 2 + 1];
-	memcpy (argv, (const char *[]) { DIFF, options }, 2 * sizeof (char *));
+	memcpy (argv, ((const char *[]) { DIFF, options }), 2 * sizeof (char *));
 	memcpy (argv + 2, diff_opts, num_diff_opts * sizeof (char *));
-	memcpy (argv + 2 + num_diff_opts, (char *[]) { tmpp1, tmpp2, NULL }, (2 + 1) * sizeof (char *));
+	memcpy (argv + 2 + num_diff_opts, ((char *[]) { tmpp1, tmpp2, NULL }), (2 + 1) * sizeof (char *));
 	in = xpipe (DIFF, &child, "r", argv);
 
 	/* Eat the first line */
@@ -1194,9 +1194,9 @@
 	fflush (NULL);
 
 	char *argv[2 + num_diff_opts + 2 + 1];
-	memcpy (argv, (const char *[]) { DIFF, options }, 2 * sizeof (char *));
+	memcpy (argv, ((const char *[]) { DIFF, options }), 2 * sizeof (char *));
 	memcpy (argv + 2, diff_opts, num_diff_opts * sizeof (char *));
-	memcpy (argv + 2 + num_diff_opts, (char *[]) { tmpp1, tmpp2, NULL }, (2 + 1) * sizeof (char *));
+	memcpy (argv + 2 + num_diff_opts, ((char *[]) { tmpp1, tmpp2, NULL }), (2 + 1) * sizeof (char *));
 	in = xpipe (DIFF, &child, "r", argv);
 
 	/* Eat the first line */
@@ -1613,9 +1613,9 @@
 		sprintf (options, "-U%d", max_context);
 
 	char *argv[2 + num_diff_opts + 2 + 1];
-	memcpy (argv, (const char *[]) { DIFF, options }, 2 * sizeof (char *));
+	memcpy (argv, ((const char *[]) { DIFF, options }), 2 * sizeof (char *));
 	memcpy (argv + 2, diff_opts, num_diff_opts * sizeof (char *));
-	memcpy (argv + 2 + num_diff_opts, (const char *[]) { f1, f2, NULL }, (2 + 1) * sizeof (char *));
+	memcpy (argv + 2 + num_diff_opts, ((const char *[]) { f1, f2, NULL }), (2 + 1) * sizeof (char *));
 	if (debug) {
 		fputs ("+", stdout);
 		for (int i = 0; argv[i]; i++) {
