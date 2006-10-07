--- misc.c.orig	Wed Dec 15 10:28:45 2004
+++ misc.c	Sat Oct  7 14:34:28 2006
@@ -5,6 +5,8 @@
 #include	<fcntl.h>
 #include	<stdio.h>
 #include	<signal.h>
+#include	<stdlib.h>
+#include	<string.h>
 
 
 #ifdef HAVE_TERMIO_H
