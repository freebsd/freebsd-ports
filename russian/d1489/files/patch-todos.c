--- todos.c.orig	2003-01-02 20:17:18 UTC
+++ todos.c
@@ -31,6 +31,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include <sys/types.h>
@@ -55,8 +56,11 @@ char outbuf[NEEDSIZ];
 char outbuf[NEEDSIZ];
 #endif
 
-extern char *mktemp();
-int RENAME(), decode();
+/* extern char *mktemp(); */
+static char*	basename(char *name);
+static int	decode(FILE *fin, FILE *fout);
+static void	logo(char *name);
+static int	RENAME(char *oldname, char *newname);
 
 #include "alt2koi8.h"
 #include "koi82alt.h"
@@ -70,15 +74,13 @@ char win[] = "cp1251(win)";
 char Unix[] = "koi8-r(unix)";
 char win[] = "cp1251(win)";
 
-logo(name)
-char *name;
+static void logo(char *name)
 {
 	fprintf(stderr, "Freeware %s v1.5\n\
 Copyright (C) 1993-2003 by Andrey A. Chernov, Moscow, Russia\n", name);
 }
 
-char *basename(name)
-char *name;
+static char *basename(char *name)
 {
 	char *p;
 
@@ -314,8 +316,7 @@ usage:
 	return 0;
 }
 
-decode(fin, fout)
-FILE *fin, *fout;
+static int decode(FILE *fin, FILE *fout)
 {
 	register int c, SeeNext;
 	static char cc[2];
@@ -341,7 +342,7 @@ FILE *fin, *fout;
 			s = "";
 			goto single;
 		}
-		while (c = (unsigned char) *s++) {
+		while ((c = (unsigned char) *s++)) {
 		single:
 			if (!binary) {
 				if (SeeNext) {
@@ -375,8 +376,7 @@ char *old, *new;
 }
 #endif
 
-int RENAME(oldname, newname)
-char *oldname, *newname;
+static int RENAME(char *oldname, char *newname)
 {
    FILE *of, *nf;
    int c;
