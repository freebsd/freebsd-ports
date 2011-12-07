--- ./agent/mibgroup/hardware/fsys/fsys_getfsstats.c.orig	2011-09-28 00:53:47.000000000 -0400
+++ ./agent/mibgroup/hardware/fsys/fsys_getfsstats.c	2011-12-07 17:33:47.000000000 -0500
@@ -150,9 +150,9 @@
         if (!entry)
             continue;
 
-        memcpy( entry->path,   stats[i].f_mntonname,   sizeof(entry->path)  );
+        strncpy( entry->path,   stats[i].f_mntonname,   sizeof(entry->path)  );
         entry->path[sizeof(entry->path)-1] = '\0';
-        memcpy( entry->device, stats[i].f_mntfromname, sizeof(entry->device));
+        strncpy( entry->device, stats[i].f_mntfromname, sizeof(entry->device));
         entry->device[sizeof(entry->device)-1] = '\0';
         entry->units = stats[i].f_bsize;    /* or f_frsize */
         entry->size  = stats[i].f_blocks;
@@ -175,4 +175,5 @@
         }
         netsnmp_fsys_calculate32(entry);
     }
+    free(stats);
 }
