--- ./lib/courier-authlib/changeuidgid.c.orig	Mon Feb  2 14:43:32 2004
+++ ./lib/courier-authlib/changeuidgid.c	Mon Feb  2 14:43:57 2004
@@ -12,6 +12,7 @@
 #endif
 #include	<stdio.h>
 #include	<stdlib.h>
+#include	<string.h>
 #include	<grp.h>
 #include	<pwd.h>
 #include	<errno.h>
