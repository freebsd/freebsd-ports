--- agent/mibgroup/hardware/fsys/fsys_getfsstats.c.orig	2011-07-02 00:35:46.000000000 +0200
+++ agent/mibgroup/hardware/fsys/fsys_getfsstats.c	2011-10-27 17:32:32.000000000 +0200
@@ -150,13 +150,13 @@
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
-        entry->used  = stats[i].f_bfree;
+        entry->used  = stats[i].f_blocks - stats[i].f_bfree;
         entry->avail = stats[i].f_bavail;
         entry->inums_total = stats[i].f_files;
         entry->inums_avail = stats[i].f_ffree;
@@ -175,4 +175,5 @@
         }
         netsnmp_fsys_calculate32(entry);
     }
+    free(stats);
 }
