--- context.c.orig	2009-02-23 10:26:32 UTC
+++ context.c
@@ -46,6 +46,8 @@ static char rcsid[] =
 #include <fcntl.h>
 #include <stdlib.h>
 
+struct context cx;
+
 /*
  * Context push/pop for nested command files.
  */
