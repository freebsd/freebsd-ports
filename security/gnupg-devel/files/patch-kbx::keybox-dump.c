--- kbx/keybox-dump.c.orig	Mon Jul 22 10:33:48 2002
+++ kbx/keybox-dump.c	Wed Jan 29 17:00:08 2003
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <errno.h>
 
+#include "../jnlib/types.h"
 #include "keybox-defs.h"
 
 static ulong
