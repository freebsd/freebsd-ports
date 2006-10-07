--- vt100.c.orig	Sat Jun  3 23:31:05 2000
+++ vt100.c	Sat Oct  7 14:35:57 2006
@@ -17,6 +17,8 @@
 #include	<errno.h>
 #include	<stdio.h>
 #include	<ctype.h>
+#include	<stdlib.h>
+#include	<string.h>
 #include	"vt100.h"
 #include	"video.h"
 #include	"terminal.h"
