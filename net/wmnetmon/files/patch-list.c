--- list.c.orig	1999-07-22 12:43:11 UTC
+++ list.c
@@ -1,6 +1,8 @@
 #include "list.h"
 #include <stdlib.h>
+#if ! (defined __FreeBSD__ || defined __DragonFly__)
 #include <malloc.h>
+#endif
 #include <string.h>
 
 
