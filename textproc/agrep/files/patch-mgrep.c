
$FreeBSD$

--- mgrep.c.orig	Sat Apr 11 00:12:27 1992
+++ mgrep.c	Sun Jul 21 03:50:47 2002
@@ -1,6 +1,7 @@
 /* Copyright (c) 1991 Sun Wu and Udi Manber.  All Rights Reserved. */
 /* multipattern matcher */
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #define MAXPAT  256
 #define MAXLINE 1024
