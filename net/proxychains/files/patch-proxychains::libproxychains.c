--- proxychains/libproxychains.c.orig	Wed Jun  4 11:11:03 2003
+++ proxychains/libproxychains.c	Sat Jun 14 15:17:55 2003
@@ -14,6 +14,10 @@
  *   (at your option) any later version.                                   *
  *                                                                         *
  ***************************************************************************/
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
+
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -72,7 +76,7 @@
 
    if(!(file=fopen("./proxychains.conf","r")))
         if(!(file=fopen(buff,"r")))
-                if(!(file=fopen("/etc/proxychains.conf","r")))
+                if(!(file=fopen(PREFIX "/etc/proxychains.conf","r")))
                 {
                         perror("1");
                         exit(1);
