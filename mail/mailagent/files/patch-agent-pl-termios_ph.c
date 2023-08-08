--- agent/pl/termios/termios_ph.c.orig	2020-04-09 16:16:46.000000000 +0200
+++ agent/pl/termios/termios_ph.c	2023-05-05 23:42:03.979804000 +0200
@@ -33,7 +33,7 @@
 #define PADSTR  "..pad.. "	/* Pad string, for comment */
 
 #include "config.h"
-
+#include <stddef.h>
 #include <stdio.h>
 
 #ifdef I_STRING
@@ -85,8 +85,8 @@
 	char pack[MAX_LEN];
 	char fields[MAX_LEN];
 	char buf[MAX_LEN];
-	int row_off = (int) &win->ws_row;		/* Offset of ws_row */
-	int col_off = (int) &win->ws_col;		/* Offset of ws_col */
+	int row_off = offsetof(struct winsize, ws_row);
+	int col_off = offsetof(struct winsize, ws_col);
 	int row_len = sizeof(win->ws_row);		/* Size of ws_row */
 	int col_len = sizeof(win->ws_col);		/* Size of ws_col */
 	int last_off = 0;						/* Last offset in pack format */
@@ -142,10 +142,10 @@
 	/*
 	 * Spit out perl definitions.
 	 */
-	printf("$TIOCGWINSZ = 0x%x;\t# The TIOCGWINSZ ioctl()\n", TIOCGWINSZ);
+	printf("$TIOCGWINSZ = 0x%lx;\t# The TIOCGWINSZ ioctl()\n", (long)TIOCGWINSZ);
 	printf("$packfmt = '%s';\t\t# %s\n", pack, comment);
-	printf("$length = %d;\t\t\t# sizeof(struct winsize)\n",
-		sizeof(struct winsize));
+	printf("$length = %lu;\t\t\t# sizeof(struct winsize)\n",
+		(unsigned long)sizeof(struct winsize));
 	printf("@fields = %s;\n", fields);
 #else
 	printf("$TIOCGWINSZ = undef;\t# No termios\n");
