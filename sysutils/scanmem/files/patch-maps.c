--- maps.c.orig	2011-01-13 09:22:33 UTC
+++ maps.c
@@ -31,7 +31,6 @@
 #include <stddef.h>
 #include <stdlib.h>
 #include <string.h>
-#include <alloca.h>
 #include <stdbool.h>
 #include <unistd.h>
 
@@ -56,7 +55,7 @@ bool readmaps(pid_t target, list_t * reg
         return false;
 
     /* construct the maps filename */
-        snprintf(name, sizeof(name), "/proc/%u/maps", target);
+        snprintf(name, sizeof(name), "/compat/linux/proc/%u/maps", target);
 
         /* attempt to open the maps file */
         if ((maps = fopen(name, "r")) == NULL) {
@@ -110,7 +109,7 @@ bool readmaps(pid_t target, list_t * reg
                                 break;
                             }
                             /* test if the region is mapped to the executable */
-                            snprintf(exename, sizeof(exename), "/proc/%u/exe", target);
+                            snprintf(exename, sizeof(exename), "/compat/linux/proc/%u/exe", target);
                             if((linkbuf_size = readlink(exename, linkbuf, MAX_LINKBUF_SIZE)) > 0)
                             {
                                 linkbuf[linkbuf_size] = 0;
