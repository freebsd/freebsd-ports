--- control.c.orig.o	Thu Apr 11 00:09:33 2002
+++ control.c	Tue Aug  9 13:20:07 2005
@@ -16,8 +16,6 @@
 #include <errno.h>
 #include <string.h>
 #include <stdio.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include "l2tp.h"
@@ -1582,6 +1580,12 @@
     wbuf[pos++] = e;
     for (x = 0; x < buf->len; x++)
     {
+		// we must at least still have 3 bytes left in the worst case scenario:
+        // 1 for a possible escape, 1 for the value and 1 to end the PPP stream.
+        if(pos >= (sizeof(wbuf) - 4)) {
+            return -EINVAL;
+        }   
+
         e = *((char *) buf->start + x);
         if ((e < 0x20) || (e == PPP_ESCAPE) || (e == PPP_FLAG))
         {
