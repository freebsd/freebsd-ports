--- src/modules/rlm_attr_rewrite/rlm_attr_rewrite.c.orig	Sat Jun 18 14:29:43 2005
+++ src/modules/rlm_attr_rewrite/rlm_attr_rewrite.c	Sat Jun 18 14:31:48 2005
@@ -27,6 +27,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #ifdef HAVE_REGEX_H
 #	include <regex.h>
 #endif
