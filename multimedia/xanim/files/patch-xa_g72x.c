--- xa_g72x.c.orig	1999-03-21 22:36:25 UTC
+++ xa_g72x.c
@@ -32,6 +32,8 @@
 
 #include "xa_g72x.h"
 
+#include <stdlib.h>
+
 static short power2[15] = {1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80,
 			0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000};
 
