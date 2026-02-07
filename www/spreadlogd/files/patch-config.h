--- config.h.orig	Mon Jan  1 19:08:46 2001
+++ config.h	Sat May 14 13:00:50 2005
@@ -11,9 +11,10 @@
 #ifndef _CONFIG_H_
 #define _CONFIG_H_
 
+#include <stdio.h>
 #include <stdlib.h>
 #include <sys/file.h>
-#include <regex.h>
+#include <gnuregex.h>
 #include <sp.h>
 
 #include "hash.h"
