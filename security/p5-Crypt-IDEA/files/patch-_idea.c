--- _idea.c.orig	Sun Jan 19 11:37:03 2003
+++ _idea.c	Sun Jan 19 11:37:14 2003
@@ -5,7 +5,7 @@
 
 #include "idea.h"
 
-#include <endian.h>
+#include <machine/endian.h>
 
 #define KEYS_PER_ROUND	6
 #define ROUNDS			8 
