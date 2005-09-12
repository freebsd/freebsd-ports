--- ascii2uni.c.orig	Mon Sep 12 22:53:37 2005
+++ ascii2uni.c	Mon Sep 12 22:53:49 2005
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#define _(String) gettext(String)
 #ifdef INTLIZE
 #include <locale.h>
 #include <libintl.h>
