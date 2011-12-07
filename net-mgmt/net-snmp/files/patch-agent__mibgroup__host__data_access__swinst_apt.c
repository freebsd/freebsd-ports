--- ./agent/mibgroup/host/data_access/swinst_apt.c.orig	2011-12-07 17:42:08.000000000 -0500
+++ ./agent/mibgroup/host/data_access/swinst_apt.c	2011-12-07 17:42:15.000000000 -0500
@@ -95,7 +95,7 @@
         entry->swDate_len = 8;
 	memcpy(entry->swDate, "\0\0\1\1\0\0\0\0", 8);
     }
-    fclose(p);
+    pclose(p);
     DEBUGMSGTL(("swinst:load:arch"," loaded %d entries\n",
                 CONTAINER_SIZE(container)));
 
