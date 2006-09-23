
$FreeBSD$

--- src/modules/auth.c.orig
+++ src/modules/auth.c
@@ -44,6 +44,7 @@
 #include "config.h"
 #endif	/* HAVE_CONFIG_H */
 
+#include <sys/types.h>
 #include <stdio.h>
 #if	HAVE_STDLIB_H
 #include <stdlib.h>
