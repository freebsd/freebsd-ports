--- maps.c.orig	2017-10-13 21:53:16 UTC
+++ maps.c
@@ -31,7 +31,9 @@
 #include <stddef.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 #include <stdbool.h>
 #include <unistd.h>
 
@@ -62,7 +64,7 @@ bool sm_readmaps(pid_t target, list_t *regions, region
         return false;
 
     /* construct the maps filename */
-        snprintf(name, sizeof(name), "/proc/%u/maps", target);
+        snprintf(name, sizeof(name), "/compat/linux/proc/%u/maps", target);
 
         /* attempt to open the maps file */
         if ((maps = fopen(name, "r")) == NULL) {
@@ -73,7 +75,7 @@ bool sm_readmaps(pid_t target, list_t *regions, region
         show_info("maps file located at %s opened.\n", name);
 
         /* get executable name */
-        snprintf(exelink, sizeof(exelink), "/proc/%u/exe", target);
+        snprintf(exelink, sizeof(exelink), "/compat/linux/proc/%u/exe", target);
         linkbuf_size = readlink(exelink, exename, MAX_LINKBUF_SIZE - 1);
         if (linkbuf_size > 0)
         {
