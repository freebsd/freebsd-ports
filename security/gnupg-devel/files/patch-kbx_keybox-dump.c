--- kbx/keybox-dump.c.orig	Mon May  3 18:38:00 2004
+++ kbx/keybox-dump.c	Mon May  3 18:38:21 2004
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <errno.h>
 
+#include "../jnlib/types.h"
 #include "keybox-defs.h"
 
 static ulong
