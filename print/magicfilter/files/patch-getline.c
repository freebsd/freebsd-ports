diff -ur/getline.c getline.c
--- getline.c	Sun Dec  5 01:32:50 2004
+++ getline.c	Sun Dec  5 01:33:11 2004
@@ -34,7 +34,7 @@
  *	/pattern/	action[/hint/]	[arg {arg ...}]
  */
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include "rule.h"
