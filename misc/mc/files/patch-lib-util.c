--- lib/util.c.orig	2010-02-11 01:25:48.000000000 +0600
+++ lib/util.c	2010-02-11 01:26:03.000000000 +0600
@@ -50,6 +50,7 @@
 #include "lib/strutil.h"
 
 #include "src/file.h"		/* copy_file_file() */
+#include "src/main.h"		/* eight_bit_clean */
 
 /*In order to use everywhere the same setup 
   for the locale we use defines               */
