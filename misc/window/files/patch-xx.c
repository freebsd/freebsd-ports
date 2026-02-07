--- xx.c.orig	2009-02-23 10:26:32 UTC
+++ xx.c
@@ -46,6 +46,12 @@ static char rcsid[] =
 #include <stdlib.h>
 #include <strings.h>
 
+struct xx *xx_head, *xx_tail;
+struct xx *xx_freelist;
+
+char *xxbuf, *xxbufp, *xxbufe;
+int xxbufsize;
+
 xxinit()
 {
 	if (ttinit() < 0)
