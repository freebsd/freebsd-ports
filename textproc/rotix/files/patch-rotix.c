--- rotix.c	Fri Nov  9 17:39:12 2001
+++ rotix.c	Fri Dec  7 15:35:26 2001
@@ -26,9 +26,11 @@
 /* System includes. */
 #include <stdio.h>
 #include <stdlib.h>
-#include <getopt.h>
+#include <unistd.h>
 #include <string.h>
 
+#define getopt_long( a, b, c, d, e ) getopt( a, b, c )
+
 /* I18N */
 #include <libintl.h>
 #define _(String) gettext (String)
@@ -46,7 +47,7 @@
 	int i = 1, rotor = 13, option = 0;
 	char *arg = NULL, option_flags = 0, rotate_flags = 0;
 	
-	/* The struct used to determine which options are called. */
+	/* The struct used to determine which options are called.
 	static struct option rotix_options[] = {
 		{ "file",	1,	NULL,	'f' },
 		{ "rot",	1,	NULL,	'r' },
@@ -57,7 +58,7 @@
 		{ "help",	0,	NULL,	'h' },
 		{ "version",	0,	NULL,	'v' },
 		{ NULL,		0,	NULL,	 0  }
-	};
+	}; */
 
 
 	/* A 2-bit character array, to obfuscate a character */
