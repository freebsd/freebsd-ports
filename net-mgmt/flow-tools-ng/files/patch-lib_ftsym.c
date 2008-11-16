--- lib/ftsym.c.orig	2008-01-28 05:48:49.000000000 +0900
+++ lib/ftsym.c	2008-08-02 02:18:10.000000000 +0900
@@ -46,6 +46,7 @@
 #include <ctype.h>
 #include <stddef.h>
 #include <stdlib.h>
+#include <unistd.h>
 
 #if HAVE_STRINGS_H
  #include <strings.h>
