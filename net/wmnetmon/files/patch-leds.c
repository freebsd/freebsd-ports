--- leds.c.orig	1999-07-26 16:23:23 UTC
+++ leds.c
@@ -1,5 +1,7 @@
 #include <stdlib.h>
+#if ! (defined __FreeBSD__ || defined __DragonFly__)
 #include <malloc.h>
+#endif
 #include <X11/xpm.h>
 #include <stdio.h>
 #include "list.h"
