--- ./sesman/config.c.orig	Thu May 25 17:34:32 2006
+++ ./sesman/config.c	Sun Apr 29 12:42:28 2007
@@ -30,6 +30,8 @@
 #include "file.h"
 #include "sesman.h"
 
+#include <fcntl.h>
+
 /******************************************************************************/
 /**
  *
@@ -59,7 +61,7 @@
   struct list* param_n;
   struct list* param_v;
 
-  fd = g_file_open(SESMAN_CFG_FILE);
+  fd = open(SESMAN_CFG_FILE, O_RDONLY);
   if (-1 == fd)
   {
     g_printf("sesman: error reading config: %s\r\n", SESMAN_CFG_FILE);
